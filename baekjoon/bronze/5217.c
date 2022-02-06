/*
	테스트 케이스 개수 n 입력
	for n
		테스트 케이스 입력
	"Pairs for %d : "출력 
	연산
	연산 결과 출력
   */

#include <stdio.h>

int	main(void)
{
	int	n, num, n1, n2, max;
	int	flag = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		printf("Pairs for %d: ", num);
		if (num % 2)
			max = num / 2;
		else
			max = num / 2 - 1;
		for (n1 = 1; n1 <= max; n1++)
		{
			n2 = num - n1;
			if (n1 > n2)
				break ;
			if (flag)
				printf(", ");
			printf("%d %d", n1, n2);
			flag = 1;
		}
		flag = 0;
		printf("\n");
	}
}
