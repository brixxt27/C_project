// printf, fprintf, fopen, fwrite, fclose, perror, fseek, ftell 함수를 사용하기 위해
#include <stdio.h>
// exit, NULL을 사용하기 위해
#include <stdlib.h>

int	main(void)
{
	// 파일 입출력을 다루기 위해 FILE 구조체 포인터 변수 선언
	FILE	*pFile;
	// 파일을 생성하고, 데이터를 넣기 위해 배열 선언. 포인터로 하지 않고 배열로 한 이유는 fwrite 함수에서 두 번째 인자로 몇 바이트 만큼 출력할 것인가 물어봐서 이다.
	char	arr[] = "http://itguru.tistory.com";
	// long 자료형으로 문자열의 수를 다루기 위해 변수 하나 선언.
	long	size;

	// 파일 생성을 위해 w 옵션으로 fopen!
	pFile = fopen("myfile.txt", "w");
	// fopen 함수 NULL 가드
	if (pFile == NULL)
	{
		printf("Error: NULL");
		exit(1);
	}
	// fprintf(pFile, "%s", "http://itguru.tistory.com");
	// NUL 문자를 포함한 26개의 문자가 fwrite 함수에 의해 파일에 출력된다.
	fwrite(arr, sizeof(arr), 1, pFile);
	fclose(pFile);

	pFile = fopen("myfile.txt", "rb");
	if (pFile == NULL)
		perror("Error opening file");
	else
	{
		// file의 위치 지정자를 가장 뒤로 가져가 offset을 0만큼 준다.즉, 위치 지정자는 stream 가장 뒤에 있는 것이다.
		fseek(pFile, 0, SEEK_END);
		// ftell 함수로 stream의 위치 지정자의 현재 위치를 구한다. 이진 stream의 경우, 리턴된 값이 파일의 시작 부분에서 부터 현재 위치까지의 바이트 수를 말한다.
		size = ftell(pFile);
		// 파일을 닫는다.
		fclose(pFile);
		printf("Size of myfile.txt: %ld bytes.\n", size);
	}
	return (0);
}
