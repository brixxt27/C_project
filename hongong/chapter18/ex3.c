#include <stdio.h>
// printf, FILE 구조체, fopen, fscanf, fprintf 함수를 사용하기 위해 포함
#include <stdlib.h>
// NULL, exit 함수를 사용하기 위해 포함

int	main(void)
// 명령행 인자 없이 main 함수 선언
{
	FILE	*fp, *ofp;
	// 파일 구조체 포인터 변수 선언
	char	name[20];
	int		kor, eng, mat;
	int		tot;
	double	avg;

	fp = fopen("a.txt", "r");
	// fopen 함수를 r 옵션으로 실행. a.txt파일이 없다면 NULL을 반환한다.
	ofp = fopen("b.txt", "w");
	// fopen 함수를 w 옵션으로 실행. b.txt파일이 없어도 NULL을 반환하지 않고, 새롭게 만든다. 만약 원래 있다면 stream은 파일의 처음을 가리키기 때문에 덮어쓰기가 된다. 데이터의 손실을 주의해야 한다.
	if (fp == NULL || ofp == NULL)
		// FILE 구조체 포인터의 NULL 가드를 해준다.
	{
		printf("ERROR: fopen's error\n");
		exit(1);
		// 프로그램을 종료하며 운영체제에게 권한을 넘긴다. 정상적으로 종료되지 않았음을 나타내는 1을 인수로 갖는다.
	}
	while (1)
		// while 문으로 무한 루프를 만든다.
	{
		fscanf(fp, "%s%d%d%d", name, &kor, &eng, &mat);
		// 파일로부터 입력을 받는다. 일반적인 scanf 함수와 용도가 비슷하지만 처음에 인수로 stream 포인터를 추가적으로 받는다.
		if (feof(fp))
			// 파일의 끝을 
			break;
		tot = kor + eng + mat;
		avg = tot / 3.0;
		fprintf(ofp, "%10s%5d%7.1lf\n", name, tot, avg);
	}
	return (0);
}
