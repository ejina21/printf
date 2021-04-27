#include <unistd.h>

static void	ft_putchr(char c)
{
	write(1, &c, 1);
}

static void	print_convert(long long p)
{
	if (p < 10)
		ft_putchr(p % 16 + '0');
	else if (p == 10)
		write(1, "a", 1);
	else if (p == 11)
		write(1, "b", 1);
	else if (p == 12)
		write(1, "c", 1);
	else if (p == 13)
		write(1, "d", 1);
	else if (p == 14)
		write(1, "e", 1);
	else
		write(1, "f", 1);
}

void	converter(long long p, char hex)
{
	if (!hex)
		if (p == 0)
			return ;
	if (p >= 16)
	{
		converter(p / 16, hex);
		print_convert(p % 16);
	}
	else
		print_convert(p);
}
