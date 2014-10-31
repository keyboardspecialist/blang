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
    struct IValAST;
    struct NameAST;

    typedef std::vector<StatementAST*>    		StatementASTList;
    typedef std::vector<ExpressionAST*>			ExpressionASTList;
    typedef std::vector<ExtrnDefAST*>			ExtrnDefASTList;
    typedef std::vector<AutoDeclAST*>     		AutoDeclASTList;
    typedef std::vector<ExtrnDeclAST*>			ExtrnDeclASTList;
    typedef std::vector<IValAST*>				IValASTList;
    typedef std::vector<NameAST*>				NameASTList;

    typedef enum 	{	kAssign, kAddAssign, kSubAssign, kMulAssign, kDivAssign, kModAssign,
    					kOrAssign, kAndAssign, kXorAssign, kLshAssign, kRshAssign,
						kLtAssign, kLteAssign, kGtAssign, kGteAssign, kNqAssign, kEqAssign
    				} AssignOp_t;

    typedef enum 	{	kAdd, kSub, kMul, kDiv, kMod, kOr, kAnd, kXor, kLshift, kRshift, kLess,
    					kLessEq, kGreater, kGreaterEq, kEqual, kNotEqual
    				} BinaryOp_t;

    typedef enum	{	kDecr, kIncr, kLogNot, kBitNot, kDeRef, kAddrOf, kNegate
    				} UnaryOp_t;


    typedef enum	{	kAuto, kAutoVec, kExtrn, kExtrnVec, kInternal
    				} StorageClass_t;



    struct NodeAST
    {
        virtual ~NodeAST() {};
        virtual llvm::Value* CodeGen(CodeGenContext& context) {return NULL;};
    };

    struct ProgramAST : NodeAST
    {
        ProgramAST() {};
        ~ProgramAST() {};

        overrides llvm::Value* CodeGen(CodeGenContext& context);

        ExtrnDefASTList m_extrnDefs;
    };

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
///// DECLARATION BASE STRUCTS

    struct ExtrnDefAST : NodeAST
    {
        ExtrnDefAST() {};
        virtual ~ExtrnDefAST() {};
    };

    struct DeclAST : NodeAST
    {
    	DeclAST(NameAST* name)
    	: m_name(name)
    	{};

    	virtual ~DeclAST() {};

    	NameAST* 		m_name;
    	StorageClass_t	m_storage = kExtrn;
    };

    struct VectorDeclAST : NodeAST
    {
    	VectorDeclAST(NameAST* name, ConstExprAST* size)
    	: m_name(name),
		  m_size(size)
    	{};

    	virtual ~VectorDeclAST() {};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	NameAST* 		m_name;
    	ConstExprAST* 	m_size;
    };

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
///// EXPRESSIONS
    struct ExpressionAST : NodeAST
    {
    	ExpressionAST() {};
    	virtual ~ExpressionAST() {};
    };

    struct ConstExprAST : ExpressionAST
    {
    	ConstExprAST() {};
    	virtual ~ConstExprAST(){};
    };

    struct WordConstantAST : ConstExprAST
    {
        WordConstantAST(SizeType constExpr)
        : m_val(constExpr)
        {};

        overrides llvm::Value* CodeGen(CodeGenContext& context);

        SizeType		m_val;
    };

    struct StringConstantAST : ConstExprAST
    {
    	StringConstantAST(std::string& literal)
    	: m_literal(literal)
    	{
    		strip();
    	};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	std::string		m_literal;

    private:
    	inline void strip(void)
    	{

    	}
    };

    struct CharConstantAST : ConstExprAST
    {
    	CharConstantAST(std::string& literal)
    	: m_literal(literal)
    	{
    		strip();
    	};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	std::string		m_literal;

    private:
    	inline void strip(void)
    	{

    	}
    };

    struct NameAST : ExpressionAST
    {
        NameAST(std::string& n)
        : m_name(n)
        {};

        overrides llvm::Value* CodeGen(CodeGenContext& context);

        std::string 	m_name;
    };


    struct VectorExprAST : ExpressionAST
    {
    	VectorExprAST(ExpressionAST* vec, ExpressionAST* idx)
    	: m_vector(vec),
		  m_vIndex(idx)
    	{};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	ExpressionAST* m_vector;
    	ExpressionAST* m_vIndex;
    };

    struct FuncCallExprAST : ExpressionAST
    {
    	FuncCallExprAST(ExpressionAST* callExpr, ExpressionASTList* args)
    	: m_callExpr(callExpr),
		  m_args(args)
    	{};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	ExpressionAST*		m_callExpr;
    	ExpressionASTList*	m_args;
    };


    struct UnaryExpressionAST : ExpressionAST
    {
    	UnaryExpressionAST(UnaryOp_t op, ExpressionAST* expr, bool isPostfix)
    	: m_op(op),
		  m_expr(expr),
		  m_isPostFix(isPostFix)
    	{};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	UnaryOp_t 		m_op;
    	ExpressionAST* 	m_expr;
    	bool			m_isPostFix;
    };

    struct BinaryExpressionAST : ExpressionAST
    {
    	BinaryExpressionAST(ExpressionAST* lh, BinaryOp_t op, ExpressionAST* rh)
    	: m_leftHand(lh),
		  m_op(op),
		  m_rightHand(rh)
    	{};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	BinaryOp_t		m_op;
    	ExpressionAST*	m_leftHand;
    	ExpressionAST*	m_rightHand;
    };

    struct ConditionalExpressionAST : ExpressionAST
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

    struct AssignmentAST : ExpressionAST
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

    struct StatementAST : NodeAST
    {
    	StatementAST(){};
    	virtual ~StatementAST(){};
    };

    struct AutoDeclAST : NodeAST
    {
    	AutoDeclAST(DeclAST* decl, ConstExprAST* size)
    	: m_decl(decl),
		  m_size(size)
    	{};

    	~AutoDeclAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	DeclAST* 		m_decl;
    	ConstExprAST*	m_size;
    };


    struct AutoDeclStatementAST : StatementAST
    {
    	AutoDeclStatementAST(AutoDeclASTList* autos)
    	: m_autos(autos)
    	{};

    	~AutoDeclStatementAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	AutoDeclASTList*	m_autos;
    };


    struct ExtrnDeclLocalStatementAST : StatementAST
    {
    	ExtrnDeclLocalStatementAST(NameASTList* extrns)
    	: m_extrns(extrns)
    	{};

    	~ExtrnDeclLocalStatementAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	NameASTList*	m_extrns;
    };

    struct LabelStatementAST : StatementAST
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

    struct CaseStatementAST : StatementAST
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


    struct GotoStatementAST : StatementAST
    {
    	GotoStatementAST(NameAST* label)
    	: m_label(label)
    	{};

    	~GotoStatementAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	NameAST* m_label;
    };

    struct StatementBlockAST : StatementAST
    {
    	StatementBlockAST(StatementASTList* statements)
    	: m_statementList(statements)
    	{};

    	~StatementBlockAST() {};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	StatementASTList* m_statementList;
    };

    struct IfStatementAST : StatementAST
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

    struct WhileStatementAST : StatementAST
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

    struct SwitchStatementAST : StatementAST
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

    struct ExtrnDeclAST : ExtrnDefAST
    {
    	ExtrnDeclAST(DeclAST* decl, IValASTList* init)
    	: m_decl(decl),
		  m_init(init)
    	{};

    	~ExtrnDeclAST(){};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    	DeclAST*		m_decl;
    	IValASTList*	m_init;
    };


    struct FuncDeclAST : ExtrnDefAST
    {
    	FuncDeclAST(NameAST* name, NameList* args, StatementAST* body)
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
