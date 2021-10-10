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

char	*ft_strncpy(char *dest, char *src, unsigned int size)
{
	char	*po;
	int		count;

	count = 0;
	po = dest;
	while (*src != '\0' && size > count)
	{
		*dest++ = *src++;
		count++;
	}
	return (po);
}

char	*ft_strncat(char *dest, char *src, unsigned int size)
{
	char	*po;
	unsigned int	count;

	count = 0;
	po = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0' && size > count)
	{
		*dest++ = *src++;
		count++;
	}
	*dest = '\0';
	return (po);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*po;

	po = dest;
	while (*src != '\0')
	{
		*dest++ = *src++;
	
	}
	*dest = '\0';
	return (po);
}

int	main(void)
{
	char	str[15];
	char	res[15];
	char	*star = "**********";
	int		size;

	printf("input : ");
	scanf("%s", str);
	size = ft_strlen(str);
	if (size > 5)
	{
		ft_strncpy(res, str, 5);
		res[5] = '\0';
		ft_strncat(res, star, size - 5);
	}
	else
		ft_strcpy(res, str);
	printf("not changed words : %s, changed words : %s\n", str, res);
	return 0;
}
