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

			switch (letter)
			{
				case 'a':
					printf("%d: 'A'\n", i);
					break;
				case 'e':
					printf("%d: 'E'\n", i);
					break;
				case 'i':
					printf("%d: 'I'\n", i);
					break;
				case 'o':
					printf("%d: 'O'\n", i);
					break;
				case 'u':
					printf("%d: 'U'\n", i);
					break;
				case 'y':
					printf("%d: 'Y'\n", i);
					break;
				default:
					printf("%d: %c is not a vowel\n", i, letter);
			}
			i++;
		}
		j++;
	}
	return (0);
}
