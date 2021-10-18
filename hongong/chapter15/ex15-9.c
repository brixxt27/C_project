#include <stdio.h>

int main(void)
{
	int 	a = 10;
	double 	b = 9.9;
	void 	*vp;
	
	vp  = &a;
	printf("int : %d\n", *(int *)vp);
	vp  = &b;
	printf("double : %.1lf\n", *(double *)vp);
	return 0;
}
