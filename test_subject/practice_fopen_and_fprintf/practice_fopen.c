#include <stdio.h>
#include <stdlib.h>

int 	main(void)
{
	FILE	*fp;
	int		number;

	fp = fopen("/Users/jayoon/project/c_project/test/fileopentest.txt", "w");
	if (fp == NULL)
	{
		printf("File open failed..\n");
		exit(1);
	}
	printf("데이터를 입력하세요: ");
	scanf("%d", &number);
	fprintf(fp, "%d", number);
	fclose(fp);
	return (0);
}
