#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str1[80] = "pear";
	char str2[80] = "peach";
	char *p;
	
	printf("������ ���߿� ������ ���� �̸� : ");
	if (strcmp(str1, str2) > 0)
		p = str1;
	else
		p = str2;
	printf("%s\n", p);
	return 0;
}
