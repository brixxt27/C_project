#include <stdio.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*str != '\0')
	{
		size++;
		str++;
	}
	return (size);
}

int	main(void)
{
	char	str[15];
	char	*po = str;
	int		size;

	printf("Write some words : ");
	scanf("%s", po);
	size = ft_strlen(po);
	if (size > 4)
	{
		po += 5;
		while (*po != '\0')
		{
			*po = '*';
			po++;
		}
	}
	printf("Print merged words : %s\n", str);
	return 0;
}
