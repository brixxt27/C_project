#include <stdio.h>

int	main(void)
{
	int ary1[4] = {1,2,3,4};
	int ary2[4] = {11,12,13,14};
	int ary3[4] = {21,22,23,24};
	int *pary[3] = {ary1, ary2, ary3};
	//선언과 동시에 초기화 하지 않으면 이런 식으로 밖에 대입을 못 한다. 
	/*
	pary[0] = ary1;
	pary[1] = ary2;
	pary[2] = ary3;
	*/
	int i, j;
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4 ; j++)
		{
			printf("%20d", &pary[i][j]);
		}
		printf("\n");
	}
	//printf("%5d", pary[2][2]);
	return 0;
}
