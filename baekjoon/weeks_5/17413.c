/*
    input data. one 줄
	while arr[i]
		if '<' 를 만나면
			while (arr[i] == '>')
				i++
		else if 공백이라면
			i++;
		else (단어라면? 단어 -> 소문자, 숫자)
			first = i;
			while (arr[i] != ' ' || arr[i] != '<' || arr[i])
				i++;
			last = i - 1;
			switch_word(arr, first, last);
	print arr
   */

#include <stdio.h>
#define LEN	100002

void	switch_word(char *pa, int first, int last);

int	main(void)
{
	char	arr[LEN];
	int		first, last, i = 0;

	fgets(arr, LEN, stdin);
	while (arr[i] != '\n')
	{
		if (arr[i] == '<')
		{
			while(arr[i] != '>')
				i++;
			i++;
		}
		else if (arr[i] == ' ')
			i++;
		else
		{
			first = i;
			while (arr[i] != ' ' && arr[i] != '<' && arr[i] != '\n')
				i++;
			last = i - 1;
			switch_word(arr, first, last);
		}
	}
	arr[i] = '\0';
	printf("%s\n", arr);
	return (0);
}

void	switch_word(char *pa, int first, int last)
{
	char	tmp;

	while (first < last)
	{
		tmp = pa[first];
		pa[first] = pa[last];
		pa[last] = tmp;
		first++;
		last--;
	}
}
