/*
 * 두 수를 입력한다.
 * while 입력 받은 정수가 둘 다 0일 때까지
 *		if n1 > n2
 *			print Yes
 *		else
 *			print NO
 *		두 정수를 입력한다.
 */

#include <stdio.h>

int main(void)
{
	int a, b;

	scanf("%d%d", &a, &b);
	while (a != 0 && b != 0)
	{
		if (a > b)
			printf("Yes\n");
		else
			printf("No\n");
		scanf("%d%d", &a, &b);
	}
	return (0);
}
