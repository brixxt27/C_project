#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str1[80], str2[80];
	char *resp;
	 //���ڿ��� �迭���� �ʱ�ȭ�ϱ� ���ؼ� ������ ����� ���ÿ� ����� �Ѵ�. 
	str1[80] = "strawberry";
	str2[80] = "apple";
	
	printf("�� ���ڿ��� �Է��ϼ��� : ");
	//scanf("%s %s", str1, str2); 
	if(strlen(str1) > strlen(str2))
		resp = str1;
	else
		resp = str2;
	printf("�̸��� �� ������ : %s\n", resp);
	return 0;
}
