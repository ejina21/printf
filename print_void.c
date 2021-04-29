#include "printf.h"
#include "print_void.h"

static void	print_space(t_elem *elem)
{
	write(1, " ", 1);
	elem->len--;
}

static int	len_dec(long long p)
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

static void	dot(t_elem *elem, long long p)
{
	while (elem->len > elem->len_data && elem->len > elem->len_dot + 2)
	{
		write(1, " ", 1);
		elem->len--;
	}
	write(1, "0x", 2);
	if (!p)
		elem->len_data--;
	while (elem->len_dot > elem->len_data - 2 && elem->len_dot)
	{
		write(1, "0", 1);
		elem->len_dot--;
	}
	if (elem->len_dot == -1 && !p)
		write(1, "0", 1);
	else
		converter(p, 0);
}

static void	print_zero(long long p)
{
	write(1, "0x", 2);
	if (!p)
		write(1, "0", 1);
	else
		converter(p, 0);
}

int	print_void(t_elem *elem, int sum, va_list *ap)
{
	long long	p;

	p = va_arg(*ap, long long);
	elem->len_data = len_dec(p) + 2;
	if (!p && !elem->len_dot && elem->dot)
		elem->len_data = 2;
	sum = intmax(elem->len, elem->len_dot + 2, elem->len_data);
	if (elem->dot)
		dot(elem, p);
	else if (elem->minus)
	{
		print_zero(p);
		while (elem->len > elem->len_data)
			print_space(elem);
	}
	else if (!elem->minus)
	{
		while (elem->len > elem->len_data)
			print_space(elem);
		print_zero(p);
	}
	return (sum);
}
