#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 > *s2)
		return 1;
	else if (*s1 < *s2)
		return -1;
	else
		return 0;
}

char	*ft_strcpy(char *dst, char *src)
{
	char	*p;
	
	p = dst;
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (p);
}

int	main(void)
{
	char	str1[20];
	char	str2[20];
	char	str3[20];
	char	temp[20];
	
	printf("Input 3 words : ");
	scanf("%s%s%s", str1, str2, str3);
	if (ft_strcmp(str1, str2) > 0)
	{
		ft_strcpy(temp, str1);
		ft_strcpy(str1, str2);
		ft_strcpy(str2, temp);
	}
	if (ft_strcmp(str1, str3) > 0)
	{
		ft_strcpy(temp, str1);
		ft_strcpy(str1, str3);
		ft_strcpy(str3, temp);
	}
	if(ft_strcmp(str2, str3) > 0)
	{
		ft_strcpy(temp, str2);
		ft_strcpy(str2, str3);
		ft_strcpy(str3, temp);
	}
	printf("%s, %s, %s", str1, str2, str3);
	return 0;
}
