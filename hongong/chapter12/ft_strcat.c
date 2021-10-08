char	*ft_strcat(char *pd, char *ps)
{
	char *po;

	po = pd;
	while (*pd != '\0')
		pd++;
	while (*ps != '\0')
	{
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';
	return (po);
}
