#include <stdio.h>
#include <stdlib.h>

/*
	1. fwrite 함수로 arr 배열에 있는 내용을 fopen으로 열었던 "myfile.txt"에 넣는다.
	2. fclose 함수로 파일을 닫는다.
	3. 다시 rb 모드로 fopen 함수로 "myfile.txt"를 열고, size에 바이트 수를 넣기 위해 fseek 함수로 파일 위치 포인터를 가장 끝으로 초기화한다. 바이너리 파일일 때 ftell 함수를 이용하면 바이트 수를 카운트해준다. 이어서 fclose 함수로 다시 파일을 닫는다.
   */
int	main(void)
{
	FILE	*pFile;
	char	arr[] = "http://itguru.tistory.com";
	long	size;

	pFile = fopen("myfile.txt", "w");
	if (pFile == NULL)
	{
		printf("Error: NULL");
		exit(1);
	}
	fwrite(arr, sizeof(arr), 1, pFile);
	fclose(pFile);

	pFile = fopen("myfile.txt", "rb");
	if (pFile == NULL)
		perror("Error opening file");
	else
	{
		fseek(pFile, 0, SEEK_END);
		size = ftell(pFile);
		fclose(pFile);
		printf("Size of myfile.txt: %ld bytes.\n", size);
	}
	return (0);
}
