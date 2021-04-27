#include "printf.h"
/* from = 1 цифры к точке относятся, а 0 к ширине*/

static char	*digit(char *fmt, t_elem *elem, int from)
{
	while (*fmt >= '0' && *fmt <= '9' && *fmt)
	{
		if (from)
		{
			elem->len_dot = elem->len_dot * 10 + *fmt - '0';
			fmt++;
		}
		else
		{
			elem->len = elem->len * 10 + *fmt - '0';
			fmt++;
		}
	}
	return (fmt);
}

static void	star(t_elem *elem, int from, va_list *ap)
{
	int	i;

	i = va_arg(*ap, int);
	if (i == 0 && from)
		i = 0;
	if (i < 0)
	{
		if (from)
			i = -1;
		else
		{
			i = -i;
			elem->minus = 1;
		}
	}
	if (from)
		elem->len_dot = i;
	else
		elem->len = i;
}

static char	*flags(char *fmt, t_elem *elem, va_list *ap)
{
	while (ft_strchr("-0.*123456789", (int)*fmt) && *fmt)
	{
		if (*fmt >= '1' && *fmt <= '9')
			fmt = digit(fmt, elem, 0);
		else if (*fmt == '-' && fmt++)
			elem->minus = 1;
		else if (*fmt == '0' && fmt++)
			elem->zero = 1;
		else if (*fmt == '.')
		{
			elem->dot = 1;
			fmt++;
			if (*fmt >= '0' && *fmt <= '9')
				fmt = digit(fmt, elem, 1);
			else if (*fmt == '*')
			{
				star(elem, 1, ap);
				fmt++;
			}
		}
		else if (*fmt == '*' && fmt++)
			star(elem, 0, ap);
	}
	return (fmt);
}

static int	params(char fmt, t_elem *elem, va_list *ap)
{
	int	sum;

	sum = 0;
	if (fmt == 'c')
		sum = print_char(elem, sum, ap);
	else if (fmt == 's')
		sum = print_str(elem, sum, ap);
	else if (fmt == 'p')
		sum = print_void(elem, sum, ap);
	else if (fmt == 'd' || fmt == 'i')
		sum = print_int(elem, sum, ap);
	else if (fmt == 'u')
		sum = print_unsint(elem, sum, ap);
	else if (fmt == 'x')
		sum = print_hex(elem, sum, ap);
	else if (fmt == 'X')
		sum = print_hex_big(elem, sum, ap);
	else
		sum = print_flags(elem, sum, fmt);
	return (sum);
}

int	ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		sum;
	t_elem	elem;

	va_start(ap, fmt);
	sum = 0;
	while (*fmt)
	{
		while (*fmt != '%' && *fmt && ++sum)
			write(1, fmt++, 1);
		if (*fmt == '%')
		{
			fmt++;
			zero_list(&elem);
			fmt = flags(fmt, &elem, &ap);
			if (ft_strchr("cspdiuxX", (int)*fmt))
				sum += params(*fmt, &elem, &ap);
			else
				sum += params(*fmt, &elem, &ap);
			fmt++;
		}
	}
	va_end(ap);
	return (sum);
}
