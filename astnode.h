#pragma once

#include <iostream>
#include <vector>
#include <llvm/IR/Value.h>

#include "SizeType.h"


namespace Blang
{

    struct CodeGenContext;
    struct ExtrnDefAST;
    struct StatementAST;
    struct ExpressionAST;
    struct AutoDeclAST;
    struct ExtrnDeclAST;
    struct ConstExprAST;
    struct NameAST;

    typedef std::vector<StatementAST*>    		StatementASTList;
    typedef std::vector<ExpressionAST*>			ExpressionASTList;
    typedef std::vector<ExtrnDefAST*>			ExtrnDefASTList;
    typedef std::vector<AutoDeclAST*>     		AutoDeclASTList;
   // typedef std::vector<ExtrnDeclAST*>			ExtrnDeclASTList;
    typedef std::vector<ConstExprAST*>  		ConstExprASTList;
    typedef std::vector<NameAST*>				NameASTList;

    typedef enum 	{	kAssign, kAddAssign, kSubAssign, kMulAssign, kDivAssign, kModAssign,
    					kOrAssign, kAndAssign, kXorAssign, kLshAssign, kRshAssign,
						kLtAssign, kLteAssign, kGtAssign, kGteAssign, kNqAssign, kEqAssign
    				} AssignOp_t;

    typedef enum 	{	kAdd, kSub, kMul, kDiv, kMod, kOr, kAnd, kXor, kLshift, kRshift, kLess,
    					kLessEq, kGreater, kGreaterEq, kEqual, kNotEqual, kLogOr, kLogAnd
    				} BinaryOp_t;

    typedef enum	{	kDecr, kIncr, kLogNot, kBitNot, kDeRef, kAddrOf, kNegate
    				} UnaryOp_t;


    typedef enum	{	kAuto, kAutoVec, kExtrn, kExtrnVec, kInternal
    				} StorageClass_t;



    struct NodeAST
    {
        NodeAST() {};
        virtual ~NodeAST() {};
        virtual llvm::Value* CodeGen(CodeGenContext& context) {return NULL;}
    };

    struct ProgramAST : public NodeAST
    {
        ProgramAST() {};
        ~ProgramAST() {};

        overrides llvm::Value* CodeGen(CodeGenContext& context);

        ExtrnDefASTList m_extrnDefs;
    };

    struct ExpressionAST : public NodeAST
    {
        ExpressionAST() {};
        virtual ~ExpressionAST() {};
    };

    struct ConstExprAST : ExpressionAST
    {
        ConstExprAST() {};
        virtual ~ConstExprAST(){};
    };

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
///// DECLARATION BASE STRUCTS

    struct ExtrnDefAST : public NodeAST
    {
        ExtrnDefAST() {};
        virtual ~ExtrnDefAST() {};
    };

    struct DeclAST : public NodeAST
    {
    	DeclAST(NameAST* name)
    	: m_name(name)
    	{};

    	virtual ~DeclAST() {};

    	NameAST* 		m_name;
    	StorageClass_t	m_storage = kExtrn;
    };

    struct VectorDeclAST : public DeclAST
    {
    	VectorDeclAST(NameAST* name, ConstExprAST* size)
    	: DeclAST(name),
		  m_size(size)
    	{};

    	virtual ~VectorDeclAST() {};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	ConstExprAST* 	m_size;
    };

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
///// EXPRESSIONS

    struct WordConstantAST : public ConstExprAST
    {
        WordConstantAST(SizeType constExpr)
        : m_val(constExpr)
        {};

        overrides llvm::Value* CodeGen(CodeGenContext& context);

        SizeType		m_val;
    };

    struct StringConstantAST : public ConstExprAST
    {
    	StringConstantAST(std::string& literal)
    	: m_literal(literal)
    	{};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	std::string		m_literal;
    };

    struct CharConstantAST : public ConstExprAST
    {
    	CharConstantAST(std::string& literal)
    	: m_literal(literal)
    	{};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	std::string		m_literal;
    };

    struct NameAST : public ExpressionAST
    {
        NameAST(std::string& n)
        : m_name(n)
        {};

        ~NameAST() {};

        overrides llvm::Value* CodeGen(CodeGenContext& context);

        std::string 	m_name;
    };


    struct VectorExprAST : public ExpressionAST
    {
    	VectorExprAST(ExpressionAST* vec, ExpressionAST* idx)
    	: m_vector(vec),
		  m_vIndex(idx)
    	{};

        ~VectorExprAST() {};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	ExpressionAST* m_vector;
    	ExpressionAST* m_vIndex;
    };

    struct FuncCallExprAST : public ExpressionAST
    {
    	FuncCallExprAST(ExpressionAST* callExpr, ExpressionASTList* args)
    	: m_callExpr(callExpr),
		  m_args(args)
    	{};

        ~FuncCallExprAST() {};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	ExpressionAST*		m_callExpr;
    	ExpressionASTList*	m_args;
    };


    struct UnaryExpressionAST : public ExpressionAST
    {
    	UnaryExpressionAST(UnaryOp_t op, ExpressionAST* expr, bool isPostfix)
    	: m_op(op),
		  m_expr(expr),
		  m_isPostFix(isPostfix)
    	{};

        ~UnaryExpressionAST() {};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	UnaryOp_t 		m_op;
    	ExpressionAST* 	m_expr;
    	bool			m_isPostFix;
    };

    struct BinaryExpressionAST : public ExpressionAST
    {
    	BinaryExpressionAST(ExpressionAST* lh, BinaryOp_t op, ExpressionAST* rh)
    	: m_leftHand(lh),
		  m_op(op),
		  m_rightHand(rh)
    	{};

        ~BinaryExpressionAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	BinaryOp_t		m_op;
    	ExpressionAST*	m_leftHand;
    	ExpressionAST*	m_rightHand;
    };

    struct ConditionalExpressionAST : public ExpressionAST
    {
    	ConditionalExpressionAST(ExpressionAST* condition, ExpressionAST* trueExpr, ExpressionAST* falseExpr)
    	: m_condition(condition),
		  m_trueExpr(trueExpr),
		  m_falseExpr(falseExpr)
    	{};

    	~ConditionalExpressionAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	ExpressionAST* m_condition;
    	ExpressionAST* m_trueExpr;
    	ExpressionAST* m_falseExpr;
    };

    struct AssignmentAST : public ExpressionAST
    {
    	AssignmentAST(ExpressionAST* lh, AssignOp_t op, ExpressionAST* rh)
    	: m_leftHand(lh),
		  m_op(op),
		  m_rightHand(rh)
    	{};

    	~AssignmentAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	AssignOp_t 		m_op;
    	ExpressionAST* 	m_leftHand;
    	ExpressionAST* 	m_rightHand;
    };

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/////// STATEMENTS

    struct StatementAST : public NodeAST
    {
    	StatementAST(){};
    	virtual ~StatementAST(){};
    };

    struct AutoDeclAST : public DeclAST
    {
    	AutoDeclAST(NameAST* name, ConstExprAST* size)
    	: DeclAST(name),
		  m_size(size)
    	{ m_storage = kAuto; };

    	~AutoDeclAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	DeclAST* 		m_decl;
    	ConstExprAST*	m_size;
    };


    struct AutoDeclStatementAST : public StatementAST
    {
    	AutoDeclStatementAST(AutoDeclASTList* autos)
    	: m_autos(autos)
    	{};

    	~AutoDeclStatementAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	AutoDeclASTList*	m_autos;
    };


    struct ExtrnDeclLocalStatementAST : public StatementAST
    {
    	ExtrnDeclLocalStatementAST(NameASTList* extrns)
    	: m_extrns(extrns)
    	{};

    	~ExtrnDeclLocalStatementAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	NameASTList*	m_extrns;
    };

    struct LabelStatementAST : public StatementAST
    {
    	LabelStatementAST(NameAST* name, StatementAST* statement)
    	: m_name(name),
		  m_statement(statement)
    	{};

    	~LabelStatementAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	NameAST* 		m_name;
    	StatementAST* 	m_statement;
    };

    struct CaseStatementAST : public StatementAST
    {
    	CaseStatementAST(ConstExprAST* val, StatementAST* statement)
    	: m_val(val),
		  m_statement(statement),
    	  m_default(false)
    	{};

    	CaseStatementAST(StatementAST* statement)
    	: m_default(true),
		  m_statement(statement),
		  m_val(NULL)
    	{};

    	~CaseStatementAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	ConstExprAST* 	m_val;
    	StatementAST*	m_statement;
    	bool			m_default;
    };


    struct GotoStatementAST : public StatementAST
    {
    	GotoStatementAST(NameAST* label)
    	: m_label(label)
    	{};

    	~GotoStatementAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	NameAST* m_label;
    };

    struct BreakStatementAST : public StatementAST
    {
        BreakStatementAST() {};
        ~BreakStatementAST() {};

        overrides llvm::Value* CodeGen(CodeGenContext& context);
    };

    struct ReturnStatementAST : public StatementAST
    {
        ReturnStatementAST(ExpressionAST* expr)
        : m_expr(expr)
        {};

        ~ReturnStatementAST() {};

        overrides llvm::Value* CodeGen(CodeGenContext& context);

        ExpressionAST* m_expr;
    };

    struct StatementBlockAST : public StatementAST
    {
    	StatementBlockAST(StatementASTList* statements)
    	: m_statementList(statements)
    	{};

    	~StatementBlockAST() {};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	StatementASTList* m_statementList;
    };

    struct IfStatementAST : public StatementAST
    {
    	IfStatementAST(ExpressionAST* expr, StatementAST* trueStmnt, StatementAST* falseStmnt)
    	: m_expr(expr),
    	  m_trueStatement(trueStmnt),
		  m_falseStatement(falseStmnt)
    	{};

    	~IfStatementAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	ExpressionAST*	m_expr;
    	StatementAST*	m_trueStatement;
    	StatementAST*	m_falseStatement;
    };

    struct WhileStatementAST : public StatementAST
    {
    	WhileStatementAST(ExpressionAST* expr, StatementAST* statement)
    	: m_expr(expr),
		  m_statement(statement)
    	{};

    	~WhileStatementAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	ExpressionAST*	m_expr;
    	StatementAST*	m_statement;
    };

    struct SwitchStatementAST : public StatementAST
    {
    	SwitchStatementAST(ExpressionAST* expr, StatementAST* statement)
    	: m_expr(expr),
		  m_statement(statement)
    	{};

    	~SwitchStatementAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	ExpressionAST*	m_expr;
    	StatementAST*	m_statement;
    };

    struct ExpressionStatementAST : public StatementAST
    {
        ExpressionStatementAST(ExpressionAST* expr)
        : m_expr(expr)
        {};

        ~ExpressionStatementAST() {};

        overrides llvm::Value* CodeGen(CodeGenContext& context);

        ExpressionAST* m_expr;
    };

    struct ExtrnDeclAST : public ExtrnDefAST
    {
    	ExtrnDeclAST(DeclAST* decl, ConstExprASTList* init)
    	: m_decl(decl),
		  m_init(init)
    	{};

    	~ExtrnDeclAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	DeclAST*		m_decl;
    	ConstExprASTList*	m_init;
    };


    struct FuncDeclAST : public ExtrnDefAST
    {
    	FuncDeclAST(NameAST* name, NameASTList* args, StatementAST* body)
    	: m_name(name),
		  m_args(args),
		  m_body(body)
    	{};

    	~FuncDeclAST(){};

    	overrides llvm::Value*	CodeGen(CodeGenContext& context);

    	NameAST*		m_name;
    	NameASTList*	m_args;
    	StatementAST*	m_body;
    };
}
