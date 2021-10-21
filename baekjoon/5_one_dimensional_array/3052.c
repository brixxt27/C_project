#include <stdio.h>

int 	main(void)
{
	int matrix[10] = {0};
	int i, j, k;
	int cnt = 0;
	int res = 10;
	
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &matrix[i]);
		matrix[i] %= 42;
	}
	for (j = 0; j < 9; j++)
	{
		for (k = 1 + j; k < 10; k++)
		{
			if (matrix[j] == matrix[k])
				cnt++;
		}
		if (cnt > 0)
			res -= 1;
		cnt = 0;	
	}
	printf("%d\n", res);
	return 0;
}
