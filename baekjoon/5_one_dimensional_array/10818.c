#include <stdio.h>

int	main(void)
{
	int	n;
	int i;
	int ary[100000];
	int max, min;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &ary[i]);
	}
	max = ary[0];
	min = ary[0];
	for (i = 1; i < n; i++)
	{
		if (max < ary[i])
			max = ary[i];
		if (min > ary[i])
			min = ary[i];
	}
	printf("%d %d", min, max);
	return 0;
}
