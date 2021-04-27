#include "printf.h"

static int	minus(t_elem *elem, char c)
{
	int	sum;

	sum = elem->len;
	write(1, &c, 1);
	while (elem->len > elem->len_data)
	{
		write (1, " ", 1);
		elem->len--;
	}
	return (sum);
}

static int	zero(t_elem *elem, char c)
{
	int	sum;

	sum = elem->len;
	while (elem->len > elem->len_data)
	{
		write (1, "0", 1);
		elem->len--;
	}
	write(1, &c, 1);
	return (sum);
}

static int	without(t_elem *elem, char c)
{
	int	sum;

	sum = elem->len;
	while (elem->len > elem->len_data)
	{
		write (1, " ", 1);
		elem->len--;
	}
	write(1, &c, 1);
	return (sum);
}

int	print_char(t_elem *elem, int sum, va_list *ap)
{
	unsigned char	c;

	elem->len_data = 1;
	c = (unsigned char)va_arg(*ap, int);
	if (elem->len <= elem->len_data)
	{
		write(1, &c, 1);
		sum++;
	}
	else if (elem->minus)
		sum = minus(elem, c);
	else if (elem->zero)
		sum = zero(elem, c);
	else if (!elem->minus)
		sum = without(elem, c);
	return (sum);
}
