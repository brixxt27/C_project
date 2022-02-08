/*	
	while 개행 나올 때까지
		공백 나오면 flag = 1;
		공백 전부 점프
		문자 나오면 flag = 0
		문자 전부 점프
	문자열 한 줄 입력
	if 단어인지 아닌지 판단
		개수 카운트
	단어 개수 출력
	종료
   */
#include <stdio.h>
#define LEN 1000002

int	count_words(char *ps);

int	main(void)
{
	char	arr[LEN];
	int		cnt;

	fgets(arr, LEN, stdin);
	cnt = count_words(arr);
	printf("%d\n", cnt);
	return (0);
}

int	count_words(char *ps)
{
	int	cnt = 0;

	while (*ps != '\n')
	{
		while (*ps == ' ')
			ps++;
		if (*ps != '\n')
		{
			cnt++;
			while(1)
			{
				if (*ps == ' ' || *ps == '\n')
					break ;
				ps++;
			}
		}
	}

	return (cnt);
}


/*
test
   */
/*
int	is_word(char *ps, int i)
{
	if ((ps[i] == ' ' && ps[i + 1] != '\n'))
		return (1);
	return (0);
}

int	count_words(char *ps)
{
	int cnt = 0, i = 0;

	if (ps[0] != ' ' && ps[1] != '\n')
		cnt++;
	while (ps[i])
	{
		if (is_word(ps, i))
			cnt++;
		i++;
	}
	return (cnt);
}
*/
