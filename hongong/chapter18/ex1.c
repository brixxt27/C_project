#include <stdio.h>
#include <stdlib.h>

//typedef struct _iodouf FILE;
int	main(void)
{
	FILE	*fp;

	fp = fopen("a.txt","r");
	if (fp == NULL)
	{
		printf("Nothing file");
		exit(1);
	}
	fclose(fp);
	return (0);
}
