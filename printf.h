#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char *fmt, ...);
typedef struct s_elem
{
	int		len_data;
	int		len;
	int		len_dot;
	char	zero;
	char	dot;
	char	minus;	
}				t_elem;
char	*ft_strchr(const char *s, int c);
int		print_hex_big(t_elem *elem, int sum, va_list *ap);
int		print_hex(t_elem *elem, int sum, va_list *ap);
int		print_unsint(t_elem *elem, int sum, va_list *ap);
int		print_int(t_elem *elem, int sum, va_list *ap);
int		print_void(t_elem *elem, int sum, va_list *ap);
int		print_str(t_elem *elem, int sum, va_list *ap);
int		print_char(t_elem *elem, int sum, va_list *ap);
int		print_flags(t_elem *elem, int sum, char c);
void	zero_list(t_elem *list);
#endif
