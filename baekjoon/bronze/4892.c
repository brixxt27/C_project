/*
*	변수n0 하나 입력
 *	while 변수가 0이 아닐 때까지
 *		n1 = 3 * n0
 *		if n1 이 홀수
 *			"i. odd "출력	
 *			n2 = (n1+1)/2
 *		else
 *			"i. even " 출력
 *			n2 = n1/2
 *		n3 = 3*n2
 *		n4 = n3/9
 *		n4 출력
 *		i++
 *		변수n0 하나 입력
 */

#include <stdio.h>

int main(void)
{
	int	i = 1, n0, n1, n2, n3, n4;

	scanf("%d", &n0);
	while (n0 != 0)
	{
		n1 = 3 * n0;
		if (n1 % 2 == 1)
		{
			printf("%d. odd ", i);
			n2 = (n1 + 1) / 2;
		}
		else
		{
			printf("%d. even ", i);
			n2 = n1 / 2;
		}
		n3 = 3 * n2;
		n4 = n3 / 9;
		printf("%d\n", n4);
		scanf("%d", &n0);
		i++;
	}
	return (0);
}
