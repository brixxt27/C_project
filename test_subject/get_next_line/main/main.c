#include <stdlib.h>	// exit
#include <stdio.h>	// printf
#include <fcntl.h>	// open
#include <unistd.h>	// close
#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	char	*str1;

	if ((fd1 = open("text1", O_RDONLY)) < 0)
	{
		printf("Error of file open in fd1");
		exit(1);
	}
	while (1)
	{
		printf("%s\n", str1 = get_next_line(fd1));
		if (!str1)
			break ;
	}
	//printf("%s\n", get_next_line(0));
	close(fd1);
	free(str1);
	return (0);
}