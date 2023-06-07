/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai </var/mail/ykawai>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:30:08 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/22 14:05:42 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	int	checker(unsigned	long i, int judge, const	char *str)
{
	unsigned long	a;

	a = LONG_MAX / 10;
	if (a < i && judge == 1)
		return (-1);
	if (a == i && judge == 1)
		if (*str - '0' > 7)
			return (-1);
	if (a < i && judge == -1)
		return (-1);
	if (a == i && judge == -1)
		if (*str - '0' > 8)
			return (-2);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	ans;
	int				judge;

	ans = 0;
	judge = 1;
	while (*str == ' ' || ((int)*str >= 9 && (int)*str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		judge = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9' && *str != '\0')
	{
		if (checker(ans, judge, str) == -1)
			return (-1);
		if (checker(ans, judge, str) == -2)
			return (0);
		ans *= 10;
		ans += *str - '0';
		str++;
	}
	return ((int)(ans * judge));
}
