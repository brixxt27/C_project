#include <stdio.h>
#include <stdlib.h>

enum season { spring, summer, fall, winter };

int	main(void)
{
	enum season	ss;
	char		*pc;

	pc = NULL;
	ss = winter;
	switch (ss)
	{
		case spring : pc = "inline";
		break;
		case summer : pc = "swimming";
		break;
		case fall : pc = "trip";
		break;
		case winter : pc = "skiing";
		break;
	}
	printf("Our leisure : %s\n", pc);
	return 0;
}
