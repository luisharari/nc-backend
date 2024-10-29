# nc-backend

The backend "compiler" for the NC project. This project will eventually compile NC code into a runnable binary or execute it within the "NCVM" environment.

## Differences Between the Compiler and the "NCVM" Environment
The compiler workflow consists of three main steps:
1. **Language Model** — Parsing and interpreting NC source code.
2. **Conversion to NCVM Code** — Translating parsed code into NCVM-specific instructions.
3. **Conversion to a Runnable Application** — Generating a final executable binary.

NCVM code is designed to be small, fast, and highly portable, making it usable anywhere that supports the NCVM runtime.

> Code running in the NCVM itself, depends on an external language (like C++ or eventually NC itself through bootstrapping).

### Example of NC Code

```c++
#include <io> 

/* 
Included <io> library for the following function(s):
void printc(char list[]*) // Takes in a pointer list of characters
*/

int main()
{
    printc("Hello World!");
    return 0; 
}
