#include "printf.h"
#include "print_int.h"

static int	len_int(int p)
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

static void	wrt(t_elem *elem, char c)
{
	while (elem->len > elem->len_dot && elem->len > elem->len_data)
	{
		write(1, &c, 1);
		elem->len--;
	}
}

static void	print_dot(t_elem *elem, int i)
{
	int	count_dot;

	count_dot = elem->len_dot;
	if (!elem->len_dot)
		elem->len_data = 0;
	if (i < 0 && count_dot > elem->len_data && !elem->minus)
		elem->len_dot++;
	if (!elem->minus)
		wrt(elem, ' ');
	if (i < 0 && count_dot > elem->len_data)
	{
		count_dot++;
		i = -i;
		write(1, "-", 1);
		elem->len_dot++;
	}
	while (count_dot > elem->len_data)
	{
		write(1, "0", 1);
		count_dot--;
	}
	if (elem->len_dot)
		ft_putnbr(i);
	if (elem->minus)
		wrt(elem, ' ');
}

static void	print_zero(t_elem *elem, int i)
{
	if (i < 0)
		write(1, "-", 1);
	wrt(elem, '0');
	if (i == -2147483648)
		write(1, "2147483648", 10);
	else if (i < 0)
		i = -i;
	ft_putnbr(i);
}

int	print_int(t_elem *elem, int sum, va_list *ap)
{
	int	i;

	i = va_arg(*ap, int);
	elem->len_data = len_int(i);
	sum += intmax(elem->len, elem->len_data, elem->len_dot);
	if (elem->len < elem->len_data && elem->len_dot
		   < elem->len_data && elem->len_dot)
		ft_putnbr(i);
	else if (!elem->dot && !elem->zero && !elem->minus)
	{
		wrt(elem, ' ');
		ft_putnbr(i);
	}
	else if (elem->dot)
		print_dot(elem, i);
	else if (elem->minus)
	{
		ft_putnbr(i);
		wrt(elem, ' ');
	}
	else if (elem->zero)
		print_zero(elem, i);
	return (sum);
}
