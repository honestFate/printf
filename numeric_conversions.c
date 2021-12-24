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

int	ft_puthex_buff(t_buff *buff, unsigned long long int n, int base, char c)
{
	int		printed;
	int		digit;
	char	*hex;

	printed = 0;
	hex = (char *) malloc(11);
	if (!hex)
		return (printed);
	if (n == 0)
		hex[printed++] = '0';
	while (n != 0)
	{
		digit = n % base;
		if (digit > 9)
			hex[printed] = digit - 10 + c;
		else
			hex[printed] = digit + '0';
		n /= base;
		printed++;
	}
	hex[printed] = '\0';
	ft_putstr_buff(buff, ft_reverse(hex));
	free(hex);
	//printf("%d\n", printed);
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
	long long int			digit;
	char					*hex;

	printed = 0;
	hex = (char *) malloc(20);
	if (!hex)
		return (printed);
	if (n == 0)
		hex[printed++] = '0';
	while (n != 0)
	{
		digit = n % 16;
		if (digit > 9)
			hex[printed] = digit - 10 + 'a';
		else
			hex[printed] = digit + '0';
		n /= 16;
		printed++;
	}
	hex[printed++] = 'x';
	hex[printed++] = '0';
	hex[printed] = '\0';
	ft_putstr_buff(buff, ft_reverse(hex));
	free(hex);
	return (printed);
}
