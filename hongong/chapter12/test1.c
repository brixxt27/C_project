#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str1[80] = "pear";
	char str2[80] = "peach";
	char *p;
	
	printf("�տ��� 3���� ���ڸ� ���ϸ�?\n");
	if (strncmp(str1, str2, 4) == 0)
		p = "����.";
	else
		p = "�ٸ���.";
	printf("%s\n", p);
	return 0;
}
