/*
	단어 입력
	대소문자 구분하지 않고, 가장 많이 나온 알파벳 찾기
	1,000,000 을 넘지 않는다.
	가장 많이 사용된 알파벳을 대문자로 출력한다.
	여러 개 존재하면 ? 출력

	풀이
	단어 입력
   */

#include <stdio.h>
#define LEN 1000002

int	main(void)
{
	char	arr[LEN];
	int		alpha[26] = {0, };
	int		i = 0;
	int		max = 0;
	int		i_max = 0;
	int		cnt = 0;

	fgets(arr, LEN, stdin);
	while (arr[i] != '\n')
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z')
			alpha[arr[i] - 'A']++;
		else if (arr[i] >= 'a' && arr[i] <= 'z')
			alpha[arr[i] - 'a']++;
		i++;
	}
	max = alpha[0];
	for (i = 1; i <= 25; i++)
	{
		if (max < alpha[i])
		{
			max = alpha[i];
			i_max = i;
		}
	}
	for (i = 0; i <= 25; i++)
	{
		if (max == alpha[i])
			cnt++;
	}
	if (cnt > 1)
		printf("?\n");
	else
		printf("%c\n", i_max + 'A');
	return (0);
}
