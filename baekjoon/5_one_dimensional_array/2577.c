#include <stdio.h>

int	main(void)
{
	int n1, n2, n3;
	int res;
	int ary[9] = {0, };
	int c[10] = {0};
	int i = 0;
	int cnt = 0;

	scanf("%d%d%d", &n1, &n2, &n3);
	res = n1 * n2 * n3;
	while (1)
	{
		if (res == 0)
			break;
		ary[i] = res % 10;
		res /= 10;
		i++;
		cnt++;
	}
	for (i = 0; i < cnt; i++)
	{
		if (ary[i] == 0)
			c[0]++;
		else if (ary[i] == 1)
			c[1]++;
		else if (ary[i] == 2)
			c[2]++;
		else if (ary[i] == 3)
			c[3]++;
		else if (ary[i] == 4)
			c[4]++;
		else if (ary[i] == 5)
			c[5]++;
		else if (ary[i] == 6)
			c[6]++;
		else if (ary[i] == 7)
			c[7]++;
		else if (ary[i] == 8)
			c[8]++;
		else
			c[9]++;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", c[i]);
	}
	return 0;
}
