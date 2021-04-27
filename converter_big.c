#include <unistd.h>

static void	ft_putchr(char c)
{
	write(1, &c, 1);
}

static void	print_convert_big(int p)
{
	if (p < 10)
		ft_putchr(p % 16 + '0');
	else if (p == 10)
		write(1, "A", 1);
	else if (p == 11)
		write(1, "B", 1);
	else if (p == 12)
		write(1, "C", 1);
	else if (p == 13)
		write(1, "D", 1);
	else if (p == 14)
		write(1, "E", 1);
	else
		write(1, "F", 1);
}

void	converter_big(unsigned int p)
{
	if (p >= 16)
	{
		converter_big(p / 16);
		print_convert_big(p % 16);
	}
	else
		print_convert_big(p);
}
