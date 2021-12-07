#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("ERROR : You need more arguments.\n");
		return (1);
	}

	int	i;
	int	j;

	j = 1;
	while (argc > j)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			char	letter = argv[j][i];

			if (letter == 'a')
				printf("%d: 'a'\n", i);
			else if (letter == 'e')
				printf("%d: 'e'\n", i);
			else if (letter == 'i')
				printf("%d: 'i'\n", i);
			else if (letter == 'o')
				printf("%d: 'o'\n", i);
			else if (letter == 'u')
				printf("%d: 'u'\n", i);
			else if (letter == 'y')
				printf("%d: 'y'\n", i);
			else
				printf("%d: %c is not a vowel\n", i, letter);
			i++;
		}
		j++;
	}
	return (0);
}
