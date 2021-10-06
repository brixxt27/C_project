// chapter 8
/*
#include <stdio.h>

int	main(void)
{
	int score[5];
	int i = 0;
	int total = 0;
	double avg = 0;
	int count = 0;
	
	count = sizeof(score) / sizeof(score[0]);
	while (i < count)
	{
		scanf("%d", &score[i]);
		i++;
	}
	i = 0;
	while (i < count)
	{
		total += score[i];
		i++;
	}
	i = 0;
	avg = total / (double)count;
	while (i < count)
	{
		printf("%5d", score[i]);
		i++;
	}
	printf("\n");
	printf("ЦђБе: %.1lf\n", avg);
	return 0;
}
*/
/*
#include <stdio.h>
int	main(void)
{
	int A[3] = {1, 2, 3};
	int B[10];
	int i;
	int length;
	
	length = sizeof(B) / sizeof(int);
	while (i < length)
	{
		B[i] = A[i % 3];
		i++;
	}
	i = 0;
	while (i < length)
	{
		printf("%5d", B[i]);
		i++;
	}
	return 0;
 }
 */
 
  
