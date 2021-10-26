#include <stdio.h>

int	BSearch(int *ar, int len, int target);

int	main(void)
{
	int	arr[] = {1, 3, 5, 7, 9};
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스 : %d\n", idx);
	
	idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스 : %d\n", idx);
	return (0);
}

int	BSearch(int *ar, int len, int target)
{
	int	first = 0;
	int mid;
	int	last = len - 1;
	
	while (first <= last)
	{
		mid = (last + first) / 2;
		if (ar[mid] == target)
			return (mid);
		else
		{
			if (ar[mid] > target)
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return (-1);
}
