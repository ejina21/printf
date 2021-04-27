#include "printf.h"

void	zero_list(t_elem *list)
{
	list->len_data = 0;
	list->len = 0;
	list->len_dot = 0;
	list->zero = 0;
	list->dot = 0;
	list->minus = 0;
}
