#include <stdio.h>

int	BSearch(int *ar[]. int len, int target);

int	main(void)
{
	int	arr[] = {1, 3, 5, 7, 9};
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스 : %d\n", idx);
	return (0);
}

int	BSearch(int *ar[]. int len, int target)
{
	int i;

	for (i = 0; i < len; i++)
	{
		if (ar[i] == target)
			return
	}
}
