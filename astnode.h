#pragma once

#include <iostream>
#include <vector>
//#include <llvm/IR/Value.h>

#include "SizeType.h"

#define overrides virtual


namespace Blang
{

    class CodeGenContext;
    class NDefinition;
    class NStatement;
    class NAutoDecl;

    typedef std::vector<NStatement*>    StatementList;
    typedef std::vector<NDefinition*>   DefinitionList; //declared extrn's
    typedef std::vector<NAutoDecl*>     AutoDeclList;


    class Node
    {
    public:
        virtual ~Node() {};
    //    virtual llvm::Value* CodeGen(CodeGenContext& context) { }
    };

    class NDefinition : public Node
    {
    public:
        NDefinition() {};
    //    overrides llvm::Value* CodeGen(CodeGenContext& context);
    };


    class NProgram : public NDefinition
    {
    public:
        NProgram() {};

        DefinitionList m_extrnDefs;
    //    overrides llvm::Value* CodeGen(CodeGenContext& context);
    };

    class NRValue : public Node
    {

    };

    class NLValue : public Node
    {

    };


    class NFuncDecl : public NDefinition
    {

    };

    class NStatement : public Node
    {

    };

    class NIVal : public Node
    {

    };

    class NConstant : public NIVal
    {
    public:
        SizeType val;
        NConstant(SizeType v) : val(v) {};
    //    overrides llvm::Value* CodeGen(CodeGenContext& context);
    };

    class NName : public NIVal
    {
    public:
        std::string name;
        NName(const std::string& n) : name(n) {};
    //    overrides llvm::Value* CodeGen(CodeGenContext& context);
    };

}