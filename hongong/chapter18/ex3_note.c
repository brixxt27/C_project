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
		// 파일로부터 입력을 받는다. scanf 는 키보드로부터 입력을 받아 변수에 값을 넣는데, fscanf는 파일에서 데이터를 받아 변수에 입력한다. 현재 fp에서 값을 받아와 각 변수들 name, kor, eng, mat에 넣는 작업이다. 그럼 초기화 되지 않았던 변수들이 값을 갖는다.
		if (feof(fp))
			break;
		// 파일의 끝을 받으면 반복문을 탈출한다. 파일의 끝이란 모든 데이터를 다 읽었다는 것을 나타낸다.
		tot = kor + eng + mat;
		avg = tot / 3.0;
		// 데이터를 연산한다.
		fprintf(ofp, "%10s%5d%7.1lf\n", name, tot, avg);
		// fprintf 함수는 파일로부터 데이터를 읽고 파일에 데이터를 출력(작성)한다. printf 와 다른 점은 printf 는 표준 출력에 데이터를 출력하는데, fprintf 는 해당 FILE *stream 으로 변수들의 데이터를 작성한다.
	}
	fclose(fp);
	fclose(ofp);
	// 마지막으로 fclose 함수를 이용해 각 FILE stream 을 닫는다. 이는 데이터 활용의 효율성과 버퍼에 남았있을지도 모르는 데이터를 알맞은 목적지로 보내기 위함이다.
	return (0);
}
