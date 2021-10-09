#include <stdio.h>

int	main(void)
{
	int		score[3][4];
	int		total;
	double	avg;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		printf("input 4 points of subjects : ");
		while (j < 4)
		{
			scanf("%d", &score[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
	i = 0;
	while (i < 3)
	{
		total = 0;
		while (j < 4)
		{
			total += score[i][j];
			j++;
		}
		avg = total / (double)4;
		printf("Total : %d, Average : %.2lf\n", total, avg);
		i++;
		j = 0;
	}
	return 0;
}
