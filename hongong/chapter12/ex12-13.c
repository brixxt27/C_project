#include <stdio.h>

char *ft_strcpy(char *dst, char *src);

int main(void)
{
	char str[80] = "strawberry";
	
	printf("바뀌기 전 : %s\n", str);
	ft_strcpy(str, "apple");
	printf("바뀐 후 : %s\n", str);
	printf("다른 문자열 대입 : %s\n", ft_strcpy(str, "kiwi"));
	return 0;
}

char *ft_strcpy(char *dst, char *src)
{
	char	*p;
	
	p = dst;
	while (*dst != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (p);
}
