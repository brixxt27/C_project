#include <stdio.h>

int main(void)
{
	int n;
	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &n);
		getchar();
		sum += (n * n);
	}
	printf("%d\n", sum % 10);
	return (0);
}
