#include "printf.h"
#include "print_int.h"

static void	print_zero(t_elem *elem, int i)
{
	if (i < 0)
		write(1, "-", 1);
	wrt(elem, '0');
	if (i == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	else if (i < 0)
		i = -i;
	ft_putnbr(i);
}

static void	print_dot2(t_elem *elem, int i, int dot, int count_dot)
{
	if (i < 0 && (count_dot >= elem->len_data || elem->len > elem->len_data))
	{
		count_dot++;
		i = -i;
		write(1, "-", 1);
		elem->len_dot++;
	}
	if (dot == -1 && elem->zero && !elem->minus)
		wrt(elem, '0');
	while (count_dot > elem->len_data)
	{
		write(1, "0", 1);
		count_dot--;
	}
	if (elem->len_dot || i)
		ft_putnbr(i);
}

static void	print_dot(t_elem *elem, int i)
{
	int	count_dot;
	int	dot;

	dot = elem->len_dot;
	count_dot = elem->len_dot;
	if (!elem->len_dot && !i)
		elem->len_data = 0;
	if (i < 0 && elem->len_dot >= elem->len_data && !elem->minus)
		elem->len_dot++;
	if (!elem->minus && elem->len_dot != -1)
		wrt(elem, ' ');
	else if (!elem->minus && !elem->zero && elem->len_dot == -1)
		wrt(elem, ' ');
	print_dot2(elem, i, dot, count_dot);
	if (elem->minus)
		wrt(elem, ' ');
}

static void	prnt(t_elem *elem, int i, char minus)
{
	if (minus)
		ft_putnbr(i);
	wrt(elem, ' ');
	if (!minus)
		ft_putnbr(i);
}

int	print_int(t_elem *elem, int sum, va_list *ap)
{
	int	i;

	i = va_arg(*ap, int);
	elem->len_data = len_int(i);
	if (elem->len_dot >= elem->len && elem->len_dot >= elem->len_data && i < 0)
		sum += 1;
	if (elem->dot && elem->len_dot == 0 && !i)
		elem->len_data = 0;
	sum += intmax(elem->len, elem->len_data, elem->len_dot);
	if (elem->len < elem->len_data && elem->len_dot
		   < elem->len_data && elem->len_dot)
		ft_putnbr(i);
	else if (!elem->dot && !elem->zero && !elem->minus)
		prnt(elem, i, 0);
	else if (elem->dot)
		print_dot(elem, i);
	else if (elem->minus)
		prnt(elem, i, 1);
	else if (elem->zero)
		print_zero(elem, i);
	return (sum);
}
