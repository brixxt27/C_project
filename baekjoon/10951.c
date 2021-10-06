#include <stdio.h>

int main(void)
{
    int a, b;
    while (1)
    {
    	int n = scanf("%d%d", &a, &b);
        if (n == EOF)
            break;
        printf("%d\n", a + b);
    }
    return (0);
}
