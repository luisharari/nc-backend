# nc-backend
 The backend "compiler" for the NC project. In the future, this project will be used to compile NC code to a runnable binary, or run in the "NCVM" environment. 

 # Differences between the compiler, and "NCVM" environment. 
 The compiler has 3 steps, 
 1. Language Model -> 2. Converting to NCVM code -> 3. Converting to a real runnable application.
 NCVM code is made to be small, simple, fast, and more important, usable anywhere with the NCVM.
 Code ran in the NCVM relies on an external language, such as C++ (or soon, NC itself, through bootstrapping)

 An example of NC code: 
```
#include <io> 

/* 
Included <io> library for the following function(s):
void princ(char list[]*) // Takes in a pointer list of characters
*/

int main()
{
    printc("Hello World!");
    return 0; 
}
```
 Compared to NCVM code (awaiting example) being more close to real ASM.  
