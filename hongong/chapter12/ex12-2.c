#include <stdio.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		putchar(*str);
		str++;
	}
}

int	main(void)
{
	char *dessert = "apple";
	
	//printf("���� �Ľ��� %s\n", dessert);
	ft_putstr(dessert);
	putchar('\n');
	dessert = "banana";
	//printf("���� �Ľ��� %s\n", dessert);
	ft_putstr(dessert);
	return 0;
}
