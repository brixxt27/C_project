/*
	함수 작성
   */
#include <stdio.h>
#define SIZE	1000
#define LEN		10

long long	sum(int *a, int n)
{
	long long	ret = 0;

	for (int i = 0; i < n; i++)
	{
		ret += a[i];
	}
	return (ret);
}

int	main(void)
{
	int		a[SIZE];

	for (int i = 0; i < LEN; i++)
		a[i] = i + 1;
	printf("sum : %lld\n", sum(a, 10));
	return (0);
}
