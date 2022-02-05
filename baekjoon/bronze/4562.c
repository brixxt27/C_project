/*
 *	몇 개의 data set 을 입력 받는다.
 *	for n
 *		두 개를 입력 받는다.
 *		if a >= b
 *			printf("MMM BRAINS\n")
 *		else
 *			printf(NO BRAINS)
 */

#include <stdio.h>

int 	main(void)
{
	int n, a, b;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		if (a >= b)
			printf("MMM BRAINS\n");
		else
			printf("NO BRAINS\n");
	}
	return (0);
}
