
#include "astcodegen.h"
#include "astnode.h"


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// Extrn Definitions
llvm::Value* Blang::ProgramAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::ExtrnDeclAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::FuncDeclAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

//Expression Nodes


//Constants
////////////////////////////////////////////////////////////////////////////////////

llvm::Value* Blang::NameAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::WordConstantAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::StringConstantAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::CharConstantAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}


//Expressions
////////////////////////////////////////////////////////////////////////////////////

llvm::Value* Blang::VectorExprAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::FuncCallExprAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::UnaryExpressionAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::BinaryExpressionAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::ConditionalExpressionAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::AssignmentAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

//Statement Nodes


llvm::Value* Blang::ExpressionStatementAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

//Local declarations
////////////////////////////////////////////////////////////////////////////////////

llvm::Value* Blang::VectorDeclAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::AutoDeclAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::AutoDeclStatementAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::ExtrnDeclLocalStatementAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}


//Jump statements
////////////////////////////////////////////////////////////////////////////////////

llvm::Value* Blang::LabelStatementAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::GotoStatementAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::CaseStatementAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::BreakStatementAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::ReturnStatementAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

//Control statements
////////////////////////////////////////////////////////////////////////////////////

llvm::Value* Blang::StatementBlockAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::IfStatementAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::WhileStatementAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

llvm::Value* Blang::SwitchStatementAST::CodeGen(CodeGenContext& context)
{
	return NULL;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////