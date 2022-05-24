#include <stdio.h>	// put()
#include <string.h> // strlen()
#include <fcntl.h>	// O_WRONLY
#include <unistd.h>	// write(), read()

//#define BUFF_SIZE 5	// 버퍼의 크기가 파일 텍스트 크기보다 작다.

int	main(void)
{
	char	buff[BUFF_SIZE + 1];
	int		fd;
	ssize_t	rd_size = 0;

	if ((fd = open("./test.txt", O_RDONLY)) > 0)
	{
		while ((rd_size = read(fd, buff, BUFF_SIZE)) > 0)
		{
			printf("rd_size in loop: %zd\n", rd_size);
			buff[rd_size] = '\0';
			puts(buff); // 출력하고 개행까지 출력한다.
		}
		close(fd);
	}
	else
		printf("파일 읽기에 실패했습니다.\n");
	printf("fd:		%d\n", fd);
	printf("rd_size:	%zd\n", rd_size);
	return (0);
}
