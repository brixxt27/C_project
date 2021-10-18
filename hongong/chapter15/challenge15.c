#include <stdio.h>

void	swap(char *p, void *a, void *b);

int main(void)
{
	int		i1, i2;
	double	d1, d2;

	printf("Input height and weight of first man : ");
	scanf("%d%lf", &i1, &d1);
	printf("Input height and weight of Second man : ");
	scanf("%d%lf", &i2, &d2);
	swap("int", &i1, &i2);
	swap("double", &d1, &d2);
	printf("First man's height and weight : %d, %.1lf\n", i1, d1);
	printf("Second man's height and weight : %d, %.1lf\n", i2, d2);
	return 0;
}

void	swap(char *p, void *a, void *b)
{
	int		ti;
	double	td;

	if (*p == 'i')
	{
		ti = *(int *)a;
		*(int *)a = *(int *)b;
		*(int *)b = ti;
	}
	else
	{
		td = *(double *)a;
		*(double *)a = *(double *)b;
		*(double *)b = td;
	}
}
