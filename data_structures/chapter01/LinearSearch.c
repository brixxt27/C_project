#include <stdio.h>

int	LSearch(int *p, int len, int target);

int	main(void)
{
	int arr[] = {3, 5, 2, 4, 9};
	int idx;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스 : %d\n", idx);
	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스 : %d\n", idx);
	return (0);
}


int	LSearch(int *p, int len, int target)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (p[i] == target)
			return (i);
	}
	return (-1);
}
