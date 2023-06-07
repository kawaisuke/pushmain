/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:17:07 by ykawai            #+#    #+#             */
/*   Updated: 2023/04/13 19:43:19 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>
#include<unistd.h>
#include<stdarg.h>
#include<stdlib.h>

int	ft_char( va_list ap)
{
	char	ans;

	ans = (char)va_arg(ap, int);
	write(1, &ans, 1);
	return (1);
}

int	ft_string( va_list ap)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char *)va_arg(ap, char *);
	if (dst == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, dst, (ft_strlen(dst)));
	i += ft_strlen(dst);
	return (i);
}

int	ft_int( va_list ap)
{
	char	*temp;
	int		dst;
	int		i;

	i = 0;
	dst = (int)va_arg(ap, int);
	temp = ft_itoa(dst);
	if (temp == NULL)
		return (0);
	write(1, temp, (ft_strlen(temp)));
	i += ft_strlen(temp);
	free (temp);
	return (i);
}

int	ft_unint( va_list ap)
{
	char			*temp;
	unsigned int	dst;
	int				i;

	i = 0;
	dst = (unsigned int)va_arg(ap, unsigned int);
	temp = ft_unitoa(dst);
	if (temp == NULL)
		return (0);
	write(1, temp, (ft_strlen(temp)));
	i += ft_strlen(temp);
	free (temp);
	return (i);
}

int	ft_percent( void)
{
	write(1, "%", 1);
	return (1);
}
