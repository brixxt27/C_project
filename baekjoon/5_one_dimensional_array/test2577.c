#include <stdio.h>

int main(void)
{
	int arr[10] = {0};
	int A, B, C, mul;
	int K;
	int i;

	scanf("%d%d%d", &A, &B, &C);
	mul = A * B * C;
	while (mul != 0)
	{
		K = mul % 10;
		arr[K]++;
		mul /= 10;
	}
	for(i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}
