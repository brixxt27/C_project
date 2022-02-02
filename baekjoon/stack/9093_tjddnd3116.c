#include <stdio.h>
#include <string.h>

void    reverse_word(char *str)
{
	int index;
	int start;
	int end;

	index = 0;
	start = 0;
	while(str[index] != '\n')
	{
		if (str[index] == ' ')
		{
			for (int i = index - 1; i >= start; i--)
				printf("%c", str[i]);
			start = index + 1;
			index++;
			printf(" ");
		}
		else
		{
			index++;
		}
	}
	for (int i = index - 1; i >= start; i--)
		printf("%c", str[i]);
}

int main(void)
{
	int t;
	char str[1001];
	int index;

	index = 0;

	scanf("%d\n", &t);
	for (int i = 0; i < t; i++)
	{
		fgets(str, 1001, stdin);
		reverse_word(str);
		printf("\n");

	}
	return (0);
}
