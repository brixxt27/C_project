#include <stdio.h>

void	print1(void)
{
	int			a = 10;
	static int	b = 10;
	int			c = 10;

	a++;
	b += 2;
	c += 3;
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
}

static void	print2(void)
{
	int			d = 10;
	static int	e = 10;
	int			f = 10;

	d++;
	e += 2;
	f += 3;
	printf("%d\n", d);
	printf("%d\n", e);
	printf("%d\n", f);
}

int main(void)
{
	print1();
	print2();
	return (0);
}

