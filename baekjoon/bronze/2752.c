/*
 *	숫자 세개를 입력 받는다.
 *	오름차 순으로 정렬한다.
 *	이를 출력한다.
 *
 *	
 */
#include <stdio.h>
#define LEN 3

void	ft_sort(int *parr)
{
	int	tmp;

	for (int i = 0; i < LEN - 1; i++)
	{
		for (int j = i + 1; j < LEN; j++)
		{
			if (parr[i] > parr[j])
			{
				tmp = parr[i];
				parr[i] = parr[j];
				parr[j] = tmp;
			}
		}
	}
}

int main(void)
{
	int	arr[LEN];

	for (int i = 0; i < LEN; i++)
		scanf("%d", &arr[i]);
	ft_sort(arr);
	for (int i = 0; i < LEN; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return (0);
}
