#include <stdarg.h>
#include <unistd.h>

size_t ft_strlen(const char *s)
{
	size_t i;
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void ft_putnbr_fd_recursive(long int n, int fd)
{
	if (n > 9)
		ft_putnbr_fd_recursive(n / 10, fd);
	ft_putchar_fd('0' + (n % 10), fd);
}

void ft_putnbr_fd(int n, int fd)
{
	long int long_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		long_n = (long int)n * (-1);
	}
	else
		long_n = n;
	ft_putnbr_fd_recursive(long_n, fd);
}

void ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}


void    ft_putnbr_u(unsigned int u, int fd)
{
	long long   tmp;
	tmp = u;
	if (tmp > 9)
		ft_putnbr_u(tmp / 10, fd);
	ft_putchar_fd(tmp % 10 + '0', fd);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != 0)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	base_print(long num, char *base)
{
	int	len;

	len = 0;
	while (base[len] != 0)
		len++;
	if (num >= len)
	{
		base_print(num / len, base);
		base_print(num % len, base);
	}
	else
		write(1, &base[num], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long num;

	num = 0;
	if (base_check(base) == 1)
	{
		if (nbr < 0)
		{
			num = nbr * (-1);
			write(1, "-", 1);
		}
		else
			num = nbr;
		base_print(num, base);
	}
	return ;
}





///////////////////////////////////




void    ft_parse(char c, va_list ap)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	//else if (c == p)
	//  ft_putpointer(va_arg(ap, void *));
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		ft_putnbr_u(va_arg(ap, int), 1);
	else if (c == 'x')
		ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else
		return ;
}

int ft_body(const char *format, va_list ap)
{
	int i;
	int count;
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_parse(format[i++ + 1], ap);
		else
			count += write(1, &format[i], 1);
		++i;
	}
	return (count);
}
int ft_printf(const char *format, ...)
{
	int     count;
	va_list ap;
	va_start(ap, format);
	count = ft_body(format, ap);
	va_end(ap);
	return (count);
}



//////////////////////////////////
#include <stdio.h>
int main(void)
{
	int a, c, d, e;
	char *b;
	
	a = 1003;
	b = "abc";
	c =	77;
	d = 0x10;
	e = 12;

	//printf("%p\n", &a);
	ft_printf("%% %d %s %d %i %x\n", a, b, c, d, e);
	printf("%% %d %s %d %i %x\n", a, b, c, d, e);
	return (0);
}
