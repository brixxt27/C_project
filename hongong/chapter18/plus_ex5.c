#include <stdio.h>

int	main(void)
{
	FILE	*fp;
	char	arr1[] = "abcd\n";
	char	arr2[10];

	fp = fopen("plus5.txt", "w+");
	fwrite(arr1, sizeof(arr1), 1, fp);
	rewind(fp);
	fread(arr2, sizeof(arr2), 1, fp);
	fclose(fp);
	printf("arr1 : %s\narr2 : %s\n", arr1, arr2);
	return (0);
}
