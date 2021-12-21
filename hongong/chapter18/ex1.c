#include <stdio.h>

typedef struct _iodouf FILE;
FILE	*fp;

fp = fopen("a.txt","r");
if (fp == NULL)
{
	printf("Nothing file");
	exit(1);
}
fclose(fp);
