char *ft_strcpy(char *dst, char *src)
{
	char	*p;
	
	p = dst;
	while (*dst != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (p);
}
