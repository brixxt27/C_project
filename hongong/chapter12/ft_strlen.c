int	ft_strlen(char *ps)
{
	int	size;

	size = 0;
	while (*ps != '\0')
	{
		size++;
		ps++;
	}
	return (size);
}
