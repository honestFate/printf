/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndillon <ndillon@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:55:42 by ndillon           #+#    #+#             */
/*   Updated: 2021/12/26 16:04:22 by ndillon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# define BUFF_SIZE 100

typedef struct ring_buffer
{
	char	buffer[BUFF_SIZE];
	int		b_start;
}	t_buff;
int		ft_printf(const char *format, ...);
t_buff	*ft_create_buff(void);
void	ft_print_buff(t_buff *buff);
int		ft_putstr_buff(t_buff *buff, const char *str);
int		ft_putchar_buff(t_buff *buff, char c);
int		ft_puthex_buff(t_buff *buff, unsigned long long int n,
			int base, char c);
int		ft_putint_buff(t_buff *buff, int n);
int		ft_putptr_buff(t_buff *buff, unsigned long long int n);
int		ft_htoa(char *s, unsigned long long n, int base, char c);

#endif
