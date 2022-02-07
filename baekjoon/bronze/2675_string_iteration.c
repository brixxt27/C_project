#include <stdio.h>

int	main(void)
{
	int		T, R;
	char	S[21];
	char	*ps;

	ps = S;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &R);
		scanf("%s", S);
		while (*ps)
		{
			for (int j = 0; j < R; j++)
			{
				printf("%c", *ps);
			}
			ps++;
		}
		printf("\n");
		ps = S;
	}
	return (0);
}
