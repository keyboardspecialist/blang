#pragma once

#include "llvm/IR/Verifier.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

#include <memory>
#include <string>
#include <map>
#include <vector>

#include "astnode.h"

namespace Blang
{
	typedef std::map< std::string, llvm::Value* > VarMap_t;

	struct CodeGenContext
	{
		CodeGenContext(llvm::IRBuilder& builder)
		: m_builder(builder)
		{
			m_localVars.clear();
			m_extrnVars.clear();
			m_localExtrnVars.clear();
		}

		VarMap_t	m_localVars;		//in-scope auto decls
		VarMap_t	m_localExtrnVars;	//in-scope extrn decls
		VarMap_t	m_extrnVars;		//global extrn vars
		VarMap_t	m_funcs;

		llvm::IRBuilder& m_builder;
	};


	class IRBuilder
	{
	public:
		IRBuilder() 	{};
		~IRBuilder() 	{};

		void Init(std::string& moduleName);

		void GenerateIR(ProgramAST* astRoot);

		void OutputIR();

	private:
		llvm::LLVMContext&				m_context;
		std::unique_ptr<llvm::Module>	m_module; 
	};
}
