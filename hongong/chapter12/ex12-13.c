#include <stdio.h>

char *ft_strcpy(char *dst, char *src);

int main(void)
{
	char str[80] = "strawberry";
	
	printf("�ٲ�� �� : %s\n", str);
	ft_strcpy(str, "apple");
	printf("�ٲ� �� : %s\n", str);
	printf("�ٸ� ���ڿ� ���� : %s\n", ft_strcpy(str, "kiwi"));
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
