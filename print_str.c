#include "printf.h"
#include "print_str.h"

static void	print_space(t_elem *elem)
{
	write(1, " ", 1);
	elem->len--;
}

static void	printstd(char *s, int len)
{
	if (!s)
	{
		write(1, "(null)", len);
		return ;
	}
	write(1, s, len);
}

static int	dot(t_elem *elem, char *s)
{
	int	sum;

	sum = 0;
	if (elem->len_dot < elem->len_data && elem->len_dot != -1)
		elem->len_data = elem->len_dot;
	while (elem->len > elem->len_data && !elem->minus && ++sum)
		print_space(elem);
	if (elem->len_dot >= elem->len_data || elem->len_dot == -1)
	{
		printstd(s, elem->len_data);
		sum += elem->len_data;
	}
	else if (elem->len_dot < elem->len_data)
	{
		printstd(s, elem->len_dot);
		sum += elem->len_dot;
	}
	while (elem->len > elem->len_data && elem->minus && ++sum)
		print_space(elem);
	return (sum);
}

static int	third(t_elem *elem, char *s, char c, char	minus)
{
	int	sum;

	sum = elem->len;
	if (minus)
		printstd(s, elem->len_data);
	while (elem->len > elem->len_data)
	{
		write (1, &c, 1);
		elem->len--;
	}
	if (!minus)
		printstd(s, elem->len_data);
	return (sum);
}

int	print_str(t_elem *elem, int sum, va_list *ap)
{
	char	*s;

	s = (char *)va_arg(*ap, const char *);
	if (s)
		elem->len_data = ft_strlen(s);
	else
		elem->len_data = 6;
	if (elem->len_data >= elem->len && !elem->dot)
	{
		sum += elem->len_data;
		printstd(s, elem->len_data);
	}
	else if (elem->dot)
		sum = dot(elem, s);
	else if (elem->minus)
		sum = third(elem, s, ' ', 1);
	else if (elem->zero)
		sum = third(elem, s, '0', 0);
	else
		sum = third(elem, s, ' ', 0);
	return (sum);
}
