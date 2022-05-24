#include <stdio.h>

int initializedGlobalVariable = 0;
int uninitializedGlobalVariable;

int main()
{
    char *strPointer = "First String";
    char stringArray[100] = "Second String";
    const char stringContant[100] = "Constant String";
    static int initializedInt = 1;
    static int uninitializedInt;
    printf("main:%p\n", main);
    printf("HELLO:%p\n", "HELLO");
    printf(":%p\n", strPointer);
    printf(":%p\n", &initializedGlobalVariable);
    printf("initializedInt:%p\n", &initializedInt);
    printf("&uninitializedGlobalVariable:%p\n", &uninitializedGlobalVariable);
    printf("&uninitializedInt:%p\n", &uninitializedInt);
    printf("&strPointer:%p\n", &strPointer);
    printf("stringArray:%p\n", stringArray);
    printf("stringContant:%p\n", stringContant);
    return 0;
}
