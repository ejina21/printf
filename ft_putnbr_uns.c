#include <unistd.h>

static void	ft_putchr(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_u(unsigned int p)
{
	if (p >= 10)
	{
		ft_putnbr_u(p / 10);
		ft_putchr(p % 10 + '0');
	}
	else
		ft_putchr(p + '0');
}
