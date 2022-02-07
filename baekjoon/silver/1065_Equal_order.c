#include <stdio.h>

int	is_hansu(int N)
{
	int		n, cnt = 0;
	int		i = 0, j, k;
	int		arr[4];
	int		flag = 0;

	if (N >= 1 && N <= 99)
		cnt = N;
	else
	{
		cnt = 99;
		for (j = 100; j <= N; j++)
		{
			i = 0;
			n = j;
			while(1)
			{
				arr[i] = n % 10;
				n = n / 10;
				i++;
				if (n == 0)
					break ;
			}
			for (k = 0; k < i - 2; k++)
			{
				if (arr[k] - arr[k+1] == arr[k+1] - arr[k+2])
					flag = 1;
				else
				{
					flag = 0;
					break ;
				}
			}
			if (flag == 1)
				cnt++;
		}
	}
	return (cnt);
}

int	main(void)
{
	int		N, cnt = 0;

	scanf("%d", &N);
	cnt = is_hansu(N);
	printf("%d\n", cnt);
	return (0);
}
