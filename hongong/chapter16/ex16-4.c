#include <stdio.h>
#include <string.h>

int main(void)
{
	char	temp[80];
	char	*sp[3];
	int		i;

	for (i = 0; i < 3; i++)
	{
		printf("문자열을 입력하세요 : ");
		get(temp);
		sp[i] = (char *)malloc(sizeof(char) * strlen(temp) + )

	}
	return 0;
}
