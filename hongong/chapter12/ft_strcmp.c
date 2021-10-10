int		ft_strcmp(char *pa, char *pb)
{
	while ((*pa == *pb) && (*pa != '\0'))
	{
		pa++;
		pb++;
	}
	if (*pa > *pb)
		return (1);
	else if(*pa < *pb)
		return (-1);
	else
		return (0);
}
