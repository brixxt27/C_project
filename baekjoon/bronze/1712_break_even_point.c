#include <stdio.h>

int main(void)
{
	int		A, B, C;
	int		n = 1;

	scanf("%d%d%d", &A, &B, &C);
	if (B >= C)
	{
		printf("-1\n");
		return (0);
	}
	while (1)
	{
		if (n > A / (C - B))
		{
			printf("%d\n", n);
			break ;
		}
		n++;
	}
	return (0);
}
