#include <stdio.h>

int 	main(void)
{
	int		n;
	char	ox[80];
	int		i, j = 0;
	int		sum = 0, score = 1;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", ox);
		while (ox[j] != '\0')
		{
			if (ox[j] == 'O')
			{
				sum += score;
				score++;
			}
			else
				score = 1;
			j++;
		}
		printf("%d\n", sum);
		sum = 0;
		score = 1;
		j = 0;
	}
	return 0;
}
