#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	FILE	*fp;
	int		age;
	char	name[20];

	fp = fopen("ex4.txt", "w+");
	if (fp == NULL)
	{
		printf("Error of fopen\n");
		exit(1);
	}
	fprintf(fp, "%d\n%s", 26, "Jaesang");
	rewind(fp);
	fscanf(fp, "%d",&age);
	fgetc(fp);
	//fscanf(fp, "%s", name);
	fgets(name, sizeof(name), fp);
	printf("age:	%d\n", age);
	printf("name:	%s\n", name);
	fclose(fp);
	return (0);
}
