#include <stdio.h>
#include <ctype.h>
#include <string.h>

//전방 선언
//int		can_print_it(char ch);
void	print_letters(char arg[], int len);
void	print_arguments(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return (0);
}

void	print_arguments(int argc, char *argv[])
{
	int	i;
	int	len;

	for (i = 1; i < argc; i++)
	{
		len = strlen(argv[i]);
		print_letters(argv[i], len);
	}
}

void	print_letters(char *arg, int len)
{
	int	i = 0;

	for (i = 0; i < len; i++)
	{
		char ch = arg[i];

		if (isprint(ch))
			printf("'%c' == %d ", ch, ch);
	}
	printf("\n");
}
/*
int	can_print_it(char ch)
{
	return (isalpha(ch) || isblank(ch));
}
*/
