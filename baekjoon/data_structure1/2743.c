#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	main(void)
{
	char	str[101];
	int		len = 0;

	scanf("%s", str);	
	len = ft_strlen(str);
	printf("%d\n", len);
	return (0);
}
