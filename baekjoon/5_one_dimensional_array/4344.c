#include <stdio.h>

int		main(void)
{
	int		testcase;
	int		i, j;
	int		n;
	int		score[1000];
	int		sum = 0;
	double	avg;
	int 	cnt = 0;
	double	upavg;
	
	scanf("%d", &testcase);
	for (i = 0; i < testcase; i++)
	{
		scanf("%d", &n);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &score[j]);
			sum += score[j];
		}
		avg = sum / (double)n;
		for (j = 0; j < n; j++)
		{
			if (avg < score[j])
				cnt++;
		}
		upavg = cnt / (double)n * 100;
		printf("%.3lf%%\n", upavg);
		cnt = 0;
		sum = 0;
	}
	return 0;
}
