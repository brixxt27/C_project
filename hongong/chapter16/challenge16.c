#include <stdio.h>
#include <stdlib.h>

int		*find_prime(int *pn, int input, int num, int div, int cnt);
void	print_number(int *pn, int input);

int	main(void)
{
	int		input;
	int		*pn;
	int		i = 0;
	int		num;
	int		div = 2;
	int		cnt = 0;

	printf("양수 입력 : ");
	scanf("%d", &input);
	pn = (int *)malloc(sizeof(int) * (input - 2));
	if (pn == NULL)
	{
		printf("ERROR\n");
		return (-1);
	}
	find_prime(pn, input, num, div, cnt);
	print_number(pn, input);
	free(pn);
	return 0;
}

int		*find_prime(int *pn, int input, int num, int div, int cnt)
{
	int i;

	if (input > 2)
	{
		pn[0] = 2;
		for (i = 1; i < input - 2; i++)
		{
			num = i + 2;
			while (num >= (div * div))
			{
				if (num % div == 0)
					cnt++;
				div++;
			}
			if (cnt == 0)
				pn[i] = num;
			else
				pn[i] = -1;
			div = 2;
			cnt = 0;
		}
	}
	else
		printf("2보다 큰 자연수를 입력해주세요.\n");
	return (pn);
}

void	print_number(int *pn, int input)
{
	int i;

	for (i = 0; i < input - 2; i++)
	{
		if (pn[i] != -1)
			printf("%5d", pn[i]);
		else
			printf("%5c", 'X');
		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");
}
