#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>//DEL
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include "../libft/libft.h"
# define BUFF_SIZE 128
typedef struct ring_buffer
{
	char	buffer[BUFF_SIZE];
	int		b_start;
}	t_buff;
t_buff	*ft_create_buff(void);
void	ft_print_buff(t_buff *buff);
int		ft_putstr_buff(t_buff *buff, const char *str);
int		ft_putchar_buff(t_buff *buff, char c);
int		ft_puthex_buff(t_buff *buff, unsigned int n, int base, char c);
int		ft_putint_buff(t_buff *buff, int n);
int		ft_putptr_buff(t_buff *buff, long long int n);

#endif
