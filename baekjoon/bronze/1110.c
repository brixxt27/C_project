#include <stdio.h>

int	main(void)
{
	int	n;
	int	div = 0;
	int	rem = 0;
	int sum = 0;
	int res = 0;
	int count = 1;
	
	scanf("%d", &n);
	div = n / 10;
	rem = n % 10;
	sum = div + rem;
	res = rem * 10 + sum % 10;
	while (n != res)
	{
		div = res / 10;
		rem = res % 10;
		sum = div + rem;
		res = rem * 10 + sum % 10;
		count++;
	}
	printf("%d\n", count);
	return 0;
}
