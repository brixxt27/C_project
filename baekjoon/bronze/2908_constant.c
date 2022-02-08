/*
	세 자리 수 두 개
	이를 거꾸로 읽어서 서로 크기를 비교한다.
	두 수는 같지 않고, 0이 포함되어 있지 않다.
   */
#include <stdio.h>

int	compare(char *n1, char *n2)
{
	int	i = 2;

	while (i >= 0)
	{
		if (n1[i] > n2[i])
			return (1);
		else if (n1[i] < n2[i])
			return (0);
		i--;
	}
	return (1);
}

void	print_data(char *ps)
{
	int	i = 2;

	while(i >= 0)
	{
		printf("%c", ps[i]);
		i--;
	}
}

int	main(void)
{
	char	n1[4] = {0, }, n2[4] = {0, };

	scanf("%s", n1);
	getchar();
	scanf("%s", n2);
	getchar();

	if (compare(n1, n2))
		print_data(n1);
	else
		print_data(n2);
	return (0);
}
