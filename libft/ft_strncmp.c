/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:22:14 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/20 16:36:53 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[j] && s1[i] != '\0' && n != 0)
	{
		i++;
		j++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned char )s1[i] - (unsigned char )s2[j]);
}
