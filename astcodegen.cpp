
#include "astcodegen.h"

#include "log.h"

namespace Blang 
{
	void IRBuilder::Init(std::string& moduleName)
	{
		m_context 	= llvm::getGlobalContext();
		m_module.reset(new llvm::Module(moduleName, m_context));

		LOG_MSG("LLVM IR Module [%s] created...\n", moduleName.c_str());
		LOG_MSG("LLVM IR Environment initialized\n");
	}

	void IRBuilder::GenerateIR(ProgramAST* astRoot)
	{
		if(!astRoot)
		{
			LOG_ERR("AST root node is NULL!\n");
			return;
		}

		LOG_MSG("Beginning code genration...\n");

		llvm::IRBuilder<> builder(m_context);
		CodeGenContext context(builder);

		astRoot->CodeGen(context);

		LOG_MSG("Finished generating code...\n");
	}

	void IRBuilder::OutputIR()
	{

	}

	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////

	// Extrn Definitions
	llvm::Value* ProgramAST::CodeGen(CodeGenContext& context)
	{
		for(auto extrn : m_extrnDefs)
		{	
			//first resolve non-function extrns for lookup
			if( isa<ExtrnDeclAST>(extrn) )
			{
				extrn->CodeGen(context);
			}
		}

		for(auto extrn : m_extrnDefs)
		{
			//now resolve functions
			//context will be populated with all visible extrn vars
			if( isa<FuncDeclAST>(extrn) )
			{
				extrn->CodeGen(context);
			}
		}

		return NULL;
	}

	llvm::Value* ExtrnDeclAST::CodeGen(CodeGenContext& context)
	{
		 std::string& name = m_decl->m_name->m_name;
		 if(context.m_extrnVars[name])
		 {
		 	LOG_ERR("Extrn variable redefinition: %s\n", name.c_str());
		 	return NULL;
		 }

		 llvm::AllocaInst* 	e;
		 IntegerType* 		eTy;
		 SizeType			eSz;

#if defined(BLANG_BUILD_64BIT)
		 eTy = context.m_builder.getInt64Ty();
#else 
		 eTy = context.m_builder.getInt32Ty();
#endif

		 if(m_init == NULL)
		 {
		 	
		 }

	}

	llvm::Value* FuncDeclAST::CodeGen(CodeGenContext& context)
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

	llvm::Value* NameAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* WordConstantAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* StringConstantAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* CharConstantAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}


	//Expressions
	////////////////////////////////////////////////////////////////////////////////////

	llvm::Value* VectorExprAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* FuncCallExprAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* UnaryExpressionAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* BinaryExpressionAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* ConditionalExpressionAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* AssignmentAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////



	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////

	//Statement Nodes


	llvm::Value* ExpressionStatementAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	//Local declarations
	////////////////////////////////////////////////////////////////////////////////////

	llvm::Value* VectorDeclAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* AutoDeclAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* AutoDeclStatementAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* ExtrnDeclLocalStatementAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}


	//Jump statements
	////////////////////////////////////////////////////////////////////////////////////

	llvm::Value* LabelStatementAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* GotoStatementAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* CaseStatementAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* BreakStatementAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* ReturnStatementAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	//Control statements
	////////////////////////////////////////////////////////////////////////////////////

	llvm::Value* StatementBlockAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* IfStatementAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* WhileStatementAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	llvm::Value* SwitchStatementAST::CodeGen(CodeGenContext& context)
	{
		return NULL;
	}

	////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////

}