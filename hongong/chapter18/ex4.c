#include <stdio.h>

int	main(void)
{
	FILE	*ofp;
	int		age;
	char	name[20];

	ofp = fopen("c.txt", "w+");
	fprintf(ofp, "%d\n%s\n", 26, "Hong GD");
	rewind(ofp);
	fscanf(ofp, "%d", &age);
	fgetc(ofp);
	fgets(name, sizeof(name), ofp);
	printf("age:	%d\n", age);
	printf("name:	%s\n", name);
	fclose(ofp);
	return (0);
}
