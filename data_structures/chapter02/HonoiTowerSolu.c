/*
	if num == 1 이면 하나만 옮기고 끝
	n~2 까지 n-1 개 을 by 로 이동 시킨다.
	1 을 to로 이동시킨다.
	n~2 까지 n-1 개를 to로 이동시킨다.
   */

#include <stdio.h>

void	HanoiTowerMove(int num, char from, char by, char to);

int	main(void)
{
	HanoiTowerMove(3, A, B, C);
	return (0);
}

void	HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)
	{
		printf("원반 %d을 %c 에서 %c 로 옮긴다.\n", num, from, to);
	}
	else
	{
		printf("원반 %d을 %c 에서 %c 로 옮긴다.\n", num, from, by);
	}
}
