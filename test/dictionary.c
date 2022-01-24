#include <stdio.h>
#include <string.h>
#define SIZE 5

int main()
{
	char array[SIZE][20]; 
	int i, j, index;
	char temp[20];
	for(i =0; i < SIZE ; i++)
	{
		printf("input your name : ");
		scanf("%s", array[i]);
	}

	for(i =0; i < SIZE-1 ; i++)
	{
		index = i;
		for(j = i+1 ; j < SIZE ; j++)
		{
			if(strcmp(array[index],array[j])>0 )
				index = j;
		}
		strcpy(temp ,array[i]);
		strcpy(array[i] ,array[index]);
		strcpy(array[index],temp);
	}
	printf("result : \n");
	for(i = 0 ; i < SIZE ; i++)
		printf("%s\n", array[i]);
	printf("\n");

	return 0;

}
