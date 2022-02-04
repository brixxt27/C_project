#include <unistd.h>

#define BUF_MAX 4000000

int		my_atoi(char **p);

int	main(void)
{
	int		test_len;
	int		str_len;
	char	buf[BUF_MAX + 1] = {0, };
	char	temp;
	char	*ptr = buf;
	char	*left, *right;
	char	*out;

	str_len = read(0, buf, BUF_MAX);
	test_len = my_atoi(&ptr);
	out = ptr;
	while (*ptr)
	{
		left = ptr;
		right = ptr;
		while (*right != ' ' && *right != '\n')
			++right;
		ptr = right + 1;
		--right;
		while (left < right)
		{
			temp = *left;
			*left = *right;
			*right = temp;
			++left;
			--right;
		}
	}
	write(1, out, str_len - (out - buf));
	return (0);
}

int	my_atoi(char **p)
{
	char	*s = *p;
	int		ret = 0;

	while (*s >= 48 && *s < 58)
		ret = ret * 10 + *s++ - 48;
	*p = s + 1;
	return (ret);
}
