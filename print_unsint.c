#include "printf.h"
#include "print_unsint.h"

static int	len_unsint(unsigned int p)
{
	int	i;

	if (p == 0)
		return (1);
	i = 0;
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

static void	print_dot(t_elem *elem, unsigned int i)
{
	int	count_dot;

	count_dot = elem->len_dot;
	if (!elem->len_dot)
		elem->len_data = 0;
	if (!elem->minus)
		wrt(elem, ' ');
	while (count_dot > elem->len_data)
	{
		write(1, "0", 1);
		count_dot--;
	}
	if (i || elem->len_dot)
		ft_putnbr_u(i);
	if (elem->minus)
		wrt(elem, ' ');
}

static void	print_m_z(t_elem *elem, unsigned int i, char c, char minus)
{
	if (minus)
		ft_putnbr_u(i);
	wrt(elem, c);
	if (!minus)
		ft_putnbr_u(i);
}

int	print_unsint(t_elem *elem, int sum, va_list *ap)
{
	unsigned int	i;

	i = va_arg(*ap, unsigned int);
	elem->len_data = len_unsint(i);
	if (elem->dot && elem->len_dot == 0 && !i)
		elem->len_data = 0;
	sum += intmax(elem->len, elem->len_data, elem->len_dot);
	if (elem->len < elem->len_data && elem->len_dot
		< elem->len_data && elem->len_dot)
		ft_putnbr_u(i);
	else if (!elem->dot && !elem->zero && !elem->minus)
	{
		wrt(elem, ' ');
		ft_putnbr_u(i);
	}
	else if (elem->dot)
		print_dot(elem, i);
	else if (elem->minus)
		print_m_z(elem, i, ' ', 1);
	else if (elem->zero)
		print_m_z(elem, i, '0', 0);
	return (sum);
}
