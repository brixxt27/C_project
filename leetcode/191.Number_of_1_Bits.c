#include <stdio.h>

int main(void)
{
	unsigned int	n = 11;
	int 			cnt;

	cnt = 0;
	for (int i = 0; i < 32; i++)
	{
		printf("%d\n", 1&n);
		if (1 & n == 1)
			cnt++;
		n >>= 1;
	}
	printf("cnt : %d\n", cnt);
	return (0);
}
