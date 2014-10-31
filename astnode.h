#pragma once

#include <iostream>
#include <vector>
#include <llvm/IR/Value.h>

#include "SizeType.h"


namespace Blang
{

    class CodeGenContext;
    class ExtrnDefinitionAST;
    class StatementAST;
    class AutoDeclAST;

    typedef std::vector<StatementAST*>    		StatementASTList;
    typedef std::vector<ExtrnDefinitionAST*>	ExtrnDefinitionLASTist;
    typedef std::vector<AutoDeclAST*>     		AutoDeclASTList;


    class NodeAST
    {
    public:
        virtual ~NodeAST() {};
        virtual llvm::Value* CodeGen(CodeGenContext& context) { }
    };

    class ExtrnDefinitionAST : public NodeAST
    {
    public:
        ExtrnDefinitionAST() {};
        overrides llvm::Value* CodeGen(CodeGenContext& context);
    };


    class ProgramAST
    {
    public:
        ProgramAST() {};

        ExtrnDefinitionASTList m_extrnDefs;
        overrides llvm::Value* CodeGen(CodeGenContext& context);
    };

    class ExpressionAST : public NodeAST
    {
    public:
    	ExpressionAST() {};

    	overrides llvm::Value* CodeGen(CodeGenContext& context);

    };

    class  : public Node
    {

    };


    class NFuncDecl : public NDefinition
    {

    };

    class StatementAST : public NodeAST
    {

    };

    class IValAST : public NodeAST
    {

    };

    class ConstantAST : public IValAST
    {
    public:
        SizeType ;
        ConstantAST(SizeType v) : val(v) {};
        overrides llvm::Value* CodeGen(CodeGenContext& context);
    };

    class NName : public NIVal
    {
    public:
        std::string name;
        NName(const std::string& n) : name(n) {};
    //    overrides llvm::Value* CodeGen(CodeGenContext& context);
    };

}