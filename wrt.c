#include "printf.h"

void	wrt(t_elem *elem, char c)
{
	while (elem->len > elem->len_dot && elem->len > elem->len_data)
	{
		write(1, &c, 1);
		elem->len--;
	}
}
