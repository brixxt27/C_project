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
	
	//printf("오늘 후식은 %s\n", dessert);
	ft_putstr(dessert);
	putchar('\n');
	dessert = "banana";
	//printf("내일 후식은 %s\n", dessert);
	ft_putstr(dessert);
	return 0;
}
