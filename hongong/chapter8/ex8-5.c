#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str1[80] = "cat";
	char str2[80];

	strcpy(str1, "tiger");
	strcpy(str2, str1);
	printf("str1 : %s, str2 : %s\n", str1, str2);
	return (0);
}
