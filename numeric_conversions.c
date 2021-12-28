/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_conversions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:53:57 by ndillon           #+#    #+#             */
/*   Updated: 2021/12/28 15:45:46 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_reverse(char *s)
{
	int		i;
	int		l;
	char	c;

	i = 0;
	l = ft_strlen(s) - 1;
	while (i <= l / 2)
	{
		c = s[i];
		s[i] = s[l - i];
		s[l - i] = c;
		i++;
	}
	return (s);
}

int	ft_htoa(char *s, unsigned long long n, int base, char c)
{
	long long int	digit;
	int				printed;

	printed = 0;
	while (n != 0)
	{
		digit = n % base;
		if (digit > 9)
			s[printed] = digit - 10 + c;
		else
			s[printed] = digit + '0';
		n /= base;
		printed++;
	}
	return (printed);
}

int	ft_puthex_buff(t_buff *buff, unsigned long long int n, int base, char c)
{
	int		printed;
	char	*hex;

	printed = 0;
	hex = (char *) malloc(11);
	if (!hex)
		return (printed);
	if (n == 0)
		hex[printed++] = '0';
	printed += ft_htoa(hex, n, base, c);
	hex[printed] = '\0';
	ft_putstr_buff(buff, ft_reverse(hex));
	free(hex);
	return (printed);
}

int	ft_putint_buff(t_buff *buff, int n)
{
	char	*digit;
	int		printed;

	digit = ft_itoa(n);
	printed = ft_putstr_buff(buff, digit);
	free(digit);
	return (printed);
}

int	ft_putptr_buff(t_buff *buff, unsigned long long int n)
{
	int						printed;
	char					*hex;

	printed = 0;
	hex = (char *) malloc(20);
	if (!hex)
		return (printed);
	if (n == 0)
		hex[printed++] = '0';
	printed += ft_htoa(hex, n, 16, 'a');
	hex[printed++] = 'x';
	hex[printed++] = '0';
	hex[printed] = '\0';
	ft_putstr_buff(buff, ft_reverse(hex));
	free(hex);
	return (printed);
}
