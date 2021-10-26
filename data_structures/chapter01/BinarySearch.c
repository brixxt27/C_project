/*
   탐색할 요소를 찾으면 그 곳의 인덱스를 출력하고, 찾지 못하면 탐색 실패 메시지를 띄운다.
   */

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
	int	mid;
	int	last = len - 1;
	
	while (first <= last)
	{
		mid = (last + first) / 2;
		printf("first = %d, mid = %d, last = %d\n", first, mid, last);
		if (ar[mid] == target)
			return (mid);
		else
		{
			if (ar[mid] > target)
				last = mid - 1; //last에 -1과 first에 +1을 해주지 않는다면 배열에 찾을 요소가 없을 때 무한루프를 돈다
			else
				first = mid + 1;
		}
	}
	printf("escape : first = %d, mid = %d, last = %d\n", first, mid, last);
	return (-1);
}
