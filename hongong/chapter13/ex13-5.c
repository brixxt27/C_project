#include <stdio.h>

int	main(void)
{
	register int i;
	auto int sum;
	
	sum = 0;
	for(i = 0; i < 10000; i++)
	{
		sum += i;
	}
	printf("Result of sum : %d, i : %d\n", sum, i);
	return 0;
}
