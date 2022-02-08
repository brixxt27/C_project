/*
	수 입력

   */

#include <stdio.h>
#include <string.h>

int main(void)
{
	char	arr[16];

	fgets(arr, 16, stdin);
	if (!strcmp(arr, "1 2 3 4 5 6 7 8"))
		printf("ascending\n");
	else if (!strcmp(arr, "8 7 6 5 4 3 2 1"))
		printf("descending\n");
	else
		printf("mixed\n");
	return (0);
}
/*
int	check_scale(int	*ps)
{
	int	flag;
	int	diff;
	int i;

	diff = ps[1] - ps[0];
	if (ps[0] == 1 && diff == 1)
	{
		for (i = 1; i < 6; i++)
		{
			if (ps[i + 1] - ps[i] != 1)
				return (3);
		}
		return (1);
	}
	else if (ps[0] == 8 && diff == -1)
	{
		for (i = 1; i < 6; i++)
		{
			if (ps[i + 1] - ps[i] != -1)
				return (3);
		}
		return (2);
	}
	else
		return (3);
}

int	main(void)
{
	int	flag = 0, arr[8];
	
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &arr[i]);
	}
	flag = check_scale(arr);
	if (flag == 1)
		printf("ascending\n");
	else if (flag == 2)
		printf("descending\n");
	else
		printf("mixed\n");
	return (0);
}
*/
