#include "headers/printf.h"

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

int	ft_puthex_buff(t_buff *buff, unsigned int n, int base, char c)
{
	int		printed;
	int		digit;
	char	*hex;

	printed = 0;
	hex = (char *) malloc(11);
	if (!hex)
		return (printed);
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
	return (printed);
}

int	ft_putint_buff(t_buff *buff, int n)
{
	int		printed;
	int		digit;
	char	*dec;

	printed = 0;
	dec = (char *) malloc(11);
	if (!dec)
		return (printed);
	while (n != 0)
	{
		digit = n % 10;
		dec[printed] = digit + '0';
		n /= 10;
		printed++;
	}
	dec[printed] = '\0';
	ft_putstr_buff(buff, ft_reverse(dec));
	free(dec);
	return (printed);
}

int	ft_putptr_buff(t_buff *buff, long long int n)
{
	int		printed;
	int		digit;
	char	*hex;

	printed = 0;
	hex = (char *) malloc(16);
	if (!hex)
		return (printed);
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
