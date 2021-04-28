int	len_int(int p)
{
	int	i;

	i = 0;
	if (p == 0)
		return (1);
	if (p < 0)
		i++;
	while (p)
	{
		p /= 10;
		i++;
	}
	return (i);
}
