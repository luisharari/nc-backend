#include <iostream>

#include "parser/parser.h"
#include "vm/vm.h"


int main(int argc, char* arguments[])
{
	if (argc == 1)
	{
		std::cout << "[NC-BACKEND] Compiler backend requires multiple arguments. Pass argument --help for more information." << std::endl;
		return 0; 
	}
	else {
		for (int i = 0; i < argc - 1; i++)
		{
			char* variable = arguments[i + 1];
			
			if (strcmp(variable, "--help") == 0)
			{
				std::cout	<< "[NC-BACKEND] Flags:" << std::endl
							<< "[--vm fileName.ncvm]  Instead of compiling a normal build file, only outputs the vm code." << std::endl
							<< "[--help]  Outputs flags and options.";
			}

			if (strcmp(variable, "--vm") == 0)
			{
				char* fileName = arguments[i + 2]; // 1 for filename, 1 for actual filec
				const char test_code[] = "#include <io>\n/*Testing Comment*/\nint main() {\nprintc(\"Hello World\") return 0; }";
				std::vector<Token> tokens = parse_source(test_code);
			}
		}
	}
}