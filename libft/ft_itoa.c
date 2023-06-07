/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:10:48 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/22 19:14:02 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

static int	digit(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (12);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (0 == n)
		return (2);
	while (0 < n)
	{
		n /= 10;
		i++;
	}
	return (++i);
}

static	int	ft_tem(int n, int s, char *temp)
{
	int		end;

	end = 0;
	if (s == -1)
		end++;
	while (9 < n)
	{
		temp[end] = n % 10 + '0';
		n /= 10;
		end++;
	}
	if (0 <= n && n <= 9)
		temp[end++] = n + '0';
	temp[end] = '\0';
	return (end);
}

static	char	*ft_swap(char *ans, int s, int end)
{
	int		i;
	char	tem;

	i = 0;
	if (s == -1)
		i++;
	while (i < end)
	{
		end--;
		tem = ans[i];
		ans[i] = ans[end];
		ans[end] = tem;
		i++;
	}
	return (ans);
}

static	char	*ft_intmin(char *ans)
{
	ans[0] = '-';
	ans[1] = '2';
	ans[2] = '1';
	ans[3] = '4';
	ans[4] = '7';
	ans[5] = '4';
	ans[6] = '8';
	ans[7] = '3';
	ans[8] = '6';
	ans[9] = '4';
	ans[10] = '8';
	ans[11] = '\0';
	return (ans);
}

char	*ft_itoa(int n)
{
	char	*ans;
	int		i;
	int		s;
	int		end;

	i = 0;
	s = 0;
	ans = malloc(sizeof(char) * digit(n));
	if (ans == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_intmin(ans));
	if (n < 0)
	{
		s = -1;
		n *= -1;
		ans[i++] = '-';
	}
	end = ft_tem(n, s, ans);
	ft_swap(ans, s, end);
	return (ans);
}
