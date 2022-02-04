#include <stdio.h>

int find_max(int *p, int n)
{
	int i;
	int max = p[0];
	for (i = 1; i < n; i++)
	{
		if (max < p[i])
			max =p[i];
	}
	return (max);
}

int	main(void)
{
	int n, i;
	int score[1000];
	int max;
	double sum = 0;
	double dscore[1000];
	double	avg = 0;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &score[i]);
	}
	max = find_max(score, n);
	for (i = 0; i < n; i++)
	{
		dscore[i] = score[i] / (double)max * 100;
		sum += dscore[i];
	}
	avg = sum / n;
	printf("%lf", avg);
	return 0;
}
