/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:08:23 by ykawai            #+#    #+#             */
/*   Updated: 2023/05/21 21:08:10 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"push_swap.h"
#include<unistd.h>
#include<limits.h>
#include<libft.h>

/* int i = -1 error  */

static	int		over_integer_symbol(char *str, int symbol, size_t judge);

int	non_integer(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != '+' || str[i] != '-'))
	{
		if ('0' < str[i] && str[i] < '9')
			break ;
		if ((str[i] == '+' || str[i] == '-'))
		{
			i++;
			break ;
		}
		if (str[i] < '0' || '9' < str[i])
			return (ERROR_END);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
			return (ERROR_END);
		i++;
	}
	return (0);
}

static	int	over_integer(char *str)
{
	int		symbol;
	size_t	judge;

		symbol = 0;
		judge = 0;
	if (str[0] == '+')
		symbol = 1;
	else if (str[0] == '-')
		symbol = 2;
	return (over_integer_symbol(str, symbol, judge));
}

static	int	over_integer_symbol(char *str, int symbol, size_t judge)
{
	if (symbol == 0)
		judge = ft_strlen(str);
	else
		judge = ft_strlen(&str[1]);
	if (judge > 10)
		return (ERROR_END);
	else if (judge == 10)
	{
		if (symbol == 2)
		{
			//if (ft_strncmp(++str, ft_itoa(INT_MIN), 10) < 0)
			if (ft_strncmp(str, ft_itoa(INT_MIN), 11) > 0)
				return (ERROR_END);
		}
		else if (symbol == 1)
		{
			if (ft_strncmp(++str, ft_itoa(INT_MAX), 10) > 0)
				return (ERROR_END);
		}
		else if (symbol == 0)
		{
			if (ft_strncmp(str, ft_itoa(INT_MAX), 10) > 0)
				return (ERROR_END);
		}
	}
	return (0);
}

int	error_end(char *str)
{
	if (non_integer(str) || over_integer(str))
	{
		write(1, "Error\n", 6);
		return (ERROR_END);
	}
	return (0);
}
