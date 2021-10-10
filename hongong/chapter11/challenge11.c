#include <stdio.h>

int	main(void)
{
	int	ch;
	int	count = 0;
	int	max = 0;
	
	ch = getchar();
	while (ch != EOF)
	{
		if (ch == '\n')
		{
			if (max < count)
				max = count;
			count = 0;
			getchar();
		}
		count++;
		ch = getchar();
	}
	printf("가장 긴 단어의 길이 : %d\n", max);
	return 0;
}
