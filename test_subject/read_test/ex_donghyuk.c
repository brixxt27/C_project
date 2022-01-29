#include <stdio.h>
#include <fcntl.h>

int 	main(void)
{
	int		fd;
	char	*temp;

	fd = open("./test.txt", O_RDONLY);
	if (fd > 0)
	{
		while (temp = get_next_line(fd))
		{
			printf("%s", temp);
		}
		free(temp);
	}
	else
		printf("Open function is failed\n");
	close(fd);
	return (0);
}
