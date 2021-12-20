#include <stdio.h>

int	main(int argc, char *argv[])
{
	int i = 0;
	//int	j = 0;

	//argv 에 들어 있는 각각의 문자열을 사용한다.
	//왜 argv[0] 을 건너뛰었을까?
	
	/*
	for (i = 0, j = 1; i < argc; i++, j *= 2)
	{
		printf("arg %d: %s\n", i, argv[j]);
	}
	*/
	for (i = 0; i < 10; i++)
	{
		printf("arg %d: %s\n", i, argv[i]);
	}

	printf("argv[5] = %s\n", argv[5]);

	char	*states[5];
	
	i = 0;
	while (i < 5)
	{
		states[i] = argv[i];
		i++;
	}

	/*
	//직접 문자열 배열을 만들어 보자.
	char *states[] =
	{
		"California", "Oregon",
		"Washington", "Texas",
		NULL
	};
	*/

	/*
	printf("%c %c %c %c %c %c %c %c %c %c %c\n", states[0][0], states[0][1], states[0][2], states[0][3], states[0][4], states[0][5], states[0][6], states[0][7], states[0][8], states[0][9], states[0][10]);
	printf("%c %c %c %c %c %c %c\n", states[1][0], states[1][1], states[1][2], states[1][3], states[1][4], states[1][5], states[1][6]);
	printf("%c %c %c %c %c %c %c %c %c %c %c\n", states[2][0], states[2][1], states[2][2], states[2][3], states[2][4], states[2][5], states[2][6], states[2][7], states[2][8], states[2][9], states[2][10]);
	printf("%c %c %c %c %c %c\n", states[3][0], states[3][1], states[3][2], states[3][3], states[3][4], states[3][5]);
	*/

	int	num_states = 5;

	for (i = 0; i < num_states; i++)
	{
		printf("state %d: %s\n", i, states[i]);
	}

	return (0);
}
