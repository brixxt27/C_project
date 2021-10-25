#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char	temp[80];
	char	*sp[3];
	int		i;

	for (i = 0; i < 3; i++)
	{
		printf("문자열을 입력하세요 : ");
		fgets(temp, 80, stdin); // enter도 입력되어 temp 행렬에 들어간다.
		sp[i] = (char *)malloc(sizeof(char) * strlen(temp) + 1);
		strcpy(sp[i], temp);
	}
	for (i = 0; i < 3; i++)
	{
		printf("%s", sp[i]);
	}
	for (i = 0; i < 3; i++)
	{
		free(sp[i]); // 동적할당 영역 반환
	}
	return 0;
}
