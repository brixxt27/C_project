#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str1[80], str2[80];
	char *resp;
	 //문자열을 배열에서 초기화하기 위해선 무조건 선언과 동시에 해줘야 한다. 
	str1[80] = "strawberry";
	str2[80] = "apple";
	
	printf("두 문자열을 입력하세요 : ");
	//scanf("%s %s", str1, str2); 
	if(strlen(str1) > strlen(str2))
		resp = str1;
	else
		resp = str2;
	printf("이름이 긴 과일은 : %s\n", resp);
	return 0;
}
