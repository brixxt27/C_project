#include <stdio.h>
#define LEN 10001

void	print_self_num(int *pi)
{
	for (int i = 1; i < LEN; i++)
	{
		if (pi[i] == 0)
			printf("%d\n", i);
	}
}

int	recursive_sn(int n)
{
	int	ret = 0;

	if (n == 0)
		return (0);
	ret = n % 10 + recursive_sn(n / 10);
	return (ret);
}

void	find_self_num(int *pi)
{
	int	num, n;

	for (n = 1; n < LEN; n++)
	{
		num = n + recursive_sn(n);
		if (num > LEN - 1)
			continue ;
		pi[num] = num;
	}
}

int	main(void)
{
	int	arr[LEN] = {0, };

	find_self_num(arr);
	print_self_num(arr);
	return (0);
}
