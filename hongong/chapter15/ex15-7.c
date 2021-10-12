#include <stdio.h>

int sum(int, int);

int	main(void)
{
	int (*fp)(int, int);
	int res;

	fp = sum;
	res = (*fp)(22, 20);
	printf("res : %d\n", res);
	return 0;
}

int sum(int a, int b)
{
	return (a + b);
}
