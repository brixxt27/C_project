#include <stdio.h>

int main(void)
{
	int ary[9];
	int i;
	int max;
	int cnt = 1;
	int max_cnt = 1;
	
	for (i = 0; i < 9; i++)
	{
		scanf("%d", &ary[i]);
	}
	max = ary[0];
	for (i = 1; i < 9; i++)
	{
		cnt++;
		if (max < ary[i])
		{
			max = ary[i];
			max_cnt = cnt;
		}
	}
	printf("%d\n", max);
	printf("%d\n", max_cnt);
	return 0;
}
