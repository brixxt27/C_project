#include <stdio.h>

int a = 10;

void	func(void)
{
	a = 30;
}

int	main(void)
{
	a = 20;
	func();
	printf("%d\n", a);
}
