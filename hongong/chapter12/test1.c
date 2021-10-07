#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str1[80] = "pear";
	char str2[80] = "peach";
	char *p;
	
	printf("앞에서 3개의 문자만 비교하면?\n");
	if (strncmp(str1, str2, 4) == 0)
		p = "같다.";
	else
		p = "다르다.";
	printf("%s\n", p);
	return 0;
}
