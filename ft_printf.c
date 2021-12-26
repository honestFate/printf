/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:54:06 by ndillon           #+#    #+#             */
/*   Updated: 2021/12/26 15:54:06 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_conversation(const char *format, t_buff *buff, va_list ap)
{
	if (*format == 'c')
		return (ft_putchar_buff(buff, va_arg(ap, int)));
	else if (*format == 's')
		return (ft_putstr_buff(buff, va_arg(ap, char *)));
	else if (*format == 'd' || *format == 'i')
		return (ft_putint_buff(buff, va_arg(ap, int)));
	else if (*format == 'u')
		return (ft_puthex_buff(buff, va_arg(ap, unsigned int), 10, '0'));
	else if (*format == 'p')
		return (ft_putptr_buff(buff, va_arg(ap, long long int)));
	else if (*format == 'x')
		return (ft_puthex_buff(buff, va_arg(ap, unsigned int), 16, 'a'));
	else if (*format == 'X')
		return (ft_puthex_buff(buff, va_arg(ap, unsigned int), 16, 'A'));
	else if (*format == '%')
		return (ft_putchar_buff(buff, '%'));
	return (ft_putchar_buff(buff, *format));
}

int	ft_format(const char *format, va_list ap)
{
	int		printed;
	t_buff	*buff;

	printed = 0;
	buff = ft_create_buff();
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			printed += ft_check_conversation(++format, buff, ap);
		else
			printed += ft_putchar_buff(buff, *format);
		format++;
	}
	if (buff->b_start <= BUFF_SIZE - 1)
		ft_print_buff(buff);
	free(buff);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	int		printed;
	va_list	ap;

	if (!format)
		return (-1);
	va_start(ap, format);
	printed = ft_format(format, ap);
	va_end(ap);
	return (printed);
}
