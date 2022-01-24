#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE	*fp;
	FILE	*ofp;
	char	ch;
	
	// reading action 은 해당 디렉토리에 파일명과 동일한 파일이 없을 시 NULL을 반환한다. t 라고 넣어줘야 text 파일이라고 알 수 있다. 하지만 넣지 않아도 자동으로 t로 인식한다. 동영상이나 사진 등의 텍스트가 아닌 파일들은 텍스트 모드로 열면 안 된다. 그들은 아스키 코드가 아닌 데이터로 채워져 있기 때문이다. rb wb 등으로 바이너리 모드로 열어야 한다.
	fp = fopen("a.txt", "rt");
	ofp = fopen("b.txt", "wt");
	// 파일이 없을 시 에러 메시지를 반환하며 프로그램 종료.
	if (fp == NULL || ofp == NULL)
	{
		if (fp == NULL)
			printf("ERROR: Nothing file.\n");
		else
			printf("ERROR: You can't create file.\n");
		exit(1);
	}
	// FILE 구조체에는 위치 지정자가 있어서 while 문 내에서 따로 인덱스를 증가 시켜주지 않아도 알아서 다음 문자를 읽는다.
	ch = fgetc(fp);
	while (ch != EOF)
	{
		printf("%c", ch);
		ch = fgetc(fp);
	}
	// 비어 있는 파일을 fgetc 로 읽으면 -1 을 반환한다.
	ch = fgetc(ofp);
	while (ch != EOF)
	{
		fputc(ch, ofp);
		ch = fgetc(ofp);
	}
	printf("\n");
	fclose(fp);
	return (0);
}
