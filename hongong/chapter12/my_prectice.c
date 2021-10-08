#include <stdio.h>

int		ft_strcmp(char *pa, char *pb);
int		ft_strlen(char *ps);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strcat(char *pd, char *ps);

int	main(void)
{
	char str1[80] = "apple";
	char str2[80] = "strawberry";
	int	res = 0;
	res = ft_strcmp(str1, str2);
	printf("before copy %d\n", res);
	ft_strcpy(str1, "strawberry");
	printf("cpy str1 : %s\n", str1);
	res = ft_strcmp(str1, str2);
	printf("after copy %d\n", res);
	printf("---------------------\n");

	int size = ft_strlen(str1);
	int	i = 0;
	while (i < size)
	{
		str1[i] = 'a' + i;
		i++;
	}
	printf("add 'alphabet' str1: %s\n", str1);
	ft_strcat(str1, "klmnopqrstuvwxyz");
	printf("after   strcat str1: %s\n", str1);
	printf("---------------------\n");
	return (0);
}
