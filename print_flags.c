#include "printf.h"

static void	printC(t_elem *elem, char c)
{
	while (elem->len > elem->len_data)
	{
		write (1, &c, 1);
		elem->len--;
	}
}

int	print_flags(t_elem *elem, int sum, char c)
{
	elem->len_data = 1;
	if (elem->dot || elem->len <= elem->len_data)
	{
		write(1, &c, 1);
		sum++;
	}
	else if (elem->minus)
	{
		sum += elem->len;
		write(1, &c, 1);
		printC(elem, ' ');
	}
	else if (elem->zero)
	{
		sum += elem->len;
		printC(elem, '0');
		write(1, &c, 1);
	}
	else if (!elem->minus)
	{
		sum += elem->len;
		printC(elem, ' ');
		write(1, &c, 1);
	}
	return (sum);
}
