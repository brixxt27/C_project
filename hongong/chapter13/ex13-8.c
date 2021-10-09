#include <stdio.h>

//int	*sum(int a, int b);
int	sum(int a, int b);

int	main(void)
{
	//int	*resp;
	int	res;
	
	//resp = sum(12, 30);
	//printf("Sum is %d\n", *resp);
	res = sum(20, 22);
	printf("%d\n", res);
	return 0;
}

/*
int	*sum(int a, int b)
{
	static int res;
	
	res = a + b;
	return (&res);
}
*/

int	sum(int a, int b)
{
	int res;
	
	res = a + b;
	return (res);
}
