#include "ft_printf.h"

t_buff	*ft_create_buff(void)
{
	t_buff	*buff;

	buff = (t_buff *)malloc(sizeof(t_buff));
	buff->b_start = 0;
	return (buff);
}

void	ft_print_buff(t_buff *buff)
{
	/*write(STDOUT_FILENO, "full buff - ", 12);
	write(STDOUT_FILENO, &(buff->buffer[0]), BUFF_SIZE);
	write(STDOUT_FILENO, "\n", 1);*/
	write(STDOUT_FILENO, &(buff->buffer[0]), buff->b_start);
	buff->b_start = 0;
}

int	ft_putchar_buff(t_buff *buff, char c)
{
	buff->buffer[buff->b_start] = c;
	(buff->b_start)++;
	if (buff->b_start == BUFF_SIZE - 1)
		ft_print_buff(buff);
	return (1);
}

int	ft_putstr_buff(t_buff *buff, const char *str)
{
	int	printed;

	if (!str)
		return (ft_putstr_buff(buff, "(null)"));
	printed = 0;
	while (*str)
	{
		buff->buffer[buff->b_start] = *str;
		(buff->b_start)++;
		if (buff->b_start == BUFF_SIZE - 1)
			ft_print_buff(buff);
		str++;
		printed++;
	}
	//printf("putstr - %d\n", printed);
	return (printed);
}
