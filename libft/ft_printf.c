/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:30:05 by ykawai            #+#    #+#             */
/*   Updated: 2023/04/13 19:41:57 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>
#include<unistd.h>
#include<stdarg.h>

int	ft_char( va_list ap);
int	ft_string( va_list ap);

static	int	ft_check(char str, va_list ap)
{
	int	i;

	i = 0;
	if (str == 'c')
		i = ft_char(ap);
	else if (str == 's')
		i = ft_string(ap);
	else if (str == 'd' || str == 'i')
		i = ft_int(ap);
	else if (str == 'p')
		i = ft_print_ptr(ap);
	else if (str == 'u')
		i = ft_unint (ap);
	else if (str == 'x' || str == 'X')
		i = ft_print_hex (ap, str);
	else if (str == '%')
		i = ft_percent ();
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, str);
	i = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			i += ft_check(*str, ap);
		}
		else
		{
			write (1, str, 1);
			i++;
		}
		str++;
	}
	va_end(ap);
	return (i);
}
