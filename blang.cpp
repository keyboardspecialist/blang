#include "astcodegen.h"
#include "astnode.h"

extern int yyparse();
extern Blang::ProgramAST*	blangProgram;

int
main(int argc, char** argv)
{
	Blang::IRBuilder build;

	if(argc == 1)
    {
        cout << "Missing input file" << endl;
        return 0;
    }

    FILE* fp;
    if((fp = fopen(argv[1], "r")))
    {
        yyin = fp;
        while(!feof(yyin))
            yyparse();
    }
    else
    {
        cout << "Couldn't open file[" << argv[1] << "]" << endl;
    }

	build.Init(argv[1]);

	build.GenerateIR();

	return 0;
}
