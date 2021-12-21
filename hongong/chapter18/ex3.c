#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	FILE	*fp, *ofp;
	char	name[20];
	int		kor, eng, mat;
	int		tot;
	double	avg;

	fp = fopen("a.txt", "r");
	ofp = fopen("b.txt", "w");
	if (fp == NULL || ofp == NULL)
	{
		printf("ERROR: fopen's error\n");
		exit(1);
	}
	while (1)
	{
		fscanf(fp, "%s%d%d%d", name, &kor, &eng, &mat);
		if (feof(fp))
			break;
		tot = kor + eng + mat;
		avg = tot / 3.0;
		fprintf(ofp, "%10s%5d%7.1lf\n", name, tot, avg);
	}
	fclose(fp);
	fclose(ofp);
	return (0);
}
