#include <unistd.h>

static void	ft_putchr(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int p)
{
	if (p == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (p < 0)
	{
		write (1, "-", 1);
		p = -p;
	}
	if (p >= 10)
	{
		ft_putnbr(p / 10);
		ft_putchr(p % 10 + '0');
	}
	else
		ft_putchr(p + '0');
}
