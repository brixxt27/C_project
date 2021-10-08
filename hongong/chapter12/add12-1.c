#include <stdio.h>

void	ft_gets(char *str)
{
	char	ch;
	
	while ((ch = getchar()) != '\n')
	{
		*str = ch;
		str++;
	}
	*str = '\0';
}

int	main(void)
{
	char	str[80];
	
	ft_gets(str);
	puts(str);
	return 0;
}
