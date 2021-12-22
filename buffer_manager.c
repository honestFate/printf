#include "headers/printf.h"

t_buff	*ft_create_buff(void)
{
	t_buff	*buff;

	buff = (t_buff *)malloc(sizeof(t_buff));
	buff->b_start = 0;
	return (buff);
}

void	ft_print_buff(t_buff *buff)
{
	write(STDOUT_FILENO, &(buff->buffer[0]), buff->b_start);
	buff->b_start = 0;
}

int	ft_putchar_buff(t_buff *buff, char c)
{
	buff->buffer[buff->b_start] = c;
	if (buff->b_start == BUFF_SIZE - 1)
		ft_print_buff(buff);
	(buff->b_start)++;
	return (1);
}

int	ft_putstr_buff(t_buff *buff, const char *str)
{
	int	printed;

	printed = 0;
	while (*str)
	{
		if (buff->b_start == BUFF_SIZE - 1)
			ft_print_buff(buff);
		buff->buffer[buff->b_start] = *str;
		(buff->b_start)++;
		str++;
		printed++;
	}
	return (printed);
}
