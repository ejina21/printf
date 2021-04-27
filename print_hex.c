#include "printf.h"
#include "print_hex.h"

static int	len_dec(unsigned int p)
{
	int	i;

	if (p == 0)
		return (1);
	i = 0;
	while (p)
	{
		p /= 16;
		i++;
	}
	return (i);
}

static void	wrt(t_elem *elem, char c)
{
	while (elem->len > elem->len_dot && elem->len > elem->len_data)
	{
		write(1, &c, 1);
		elem->len--;
	}
}

static void	print_dot(t_elem *elem, unsigned int p)
{
	int	count_dot;

	count_dot = elem->len_dot;
	if (!elem->len_dot && !p)
		elem->len_data = 0;
	if (!elem->minus)
		wrt(elem, ' ');
	while (count_dot > elem->len_data)
	{
		write(1, "0", 1);
		count_dot--;
	}
	if (p || elem->len_dot)
		converter(p, 1);
	if (elem->minus)
		wrt(elem, ' ');
}

static void	print_m_z(t_elem *elem, unsigned int p, char c, char minus)
{
	if (minus)
		converter(p, 1);
	wrt(elem, c);
	if (!minus)
		converter(p, 1);
}

int	print_hex(t_elem *elem, int sum, va_list *ap)
{
	unsigned int	p;

	p = va_arg(*ap, unsigned int);
	elem->len_data = len_dec(p);
	if (elem->dot && elem->len_dot == 0 && !p)
		elem->len_data = 0;
	sum = intmax(elem->len, elem->len_data, elem->len_dot);
	if (elem->len < elem->len_data && elem->len_dot
		< elem->len_data && elem->len_dot)
		converter(p, 1);
	else if (!elem->dot && !elem->zero && !elem->minus)
	{
		wrt(elem, ' ');
		converter(p, 1);
	}
	else if (elem->dot)
		print_dot(elem, p);
	else if (elem->minus)
		print_m_z(elem, p, ' ', 1);
	else if (elem->zero)
		print_m_z(elem, p, '0', 0);
	return (sum);
}
