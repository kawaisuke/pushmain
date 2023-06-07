/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:33:10 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/19 19:29:11 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	const char		*t;
	unsigned char	*search;
	int				i;

	t = (const char *)s;
	search = (unsigned char *)t;
	uc = (unsigned char)c;
	i = 0;
	while (0 < n)
	{
		if (search[i] == uc)
			return (&search[i]);
		i++;
		n--;
	}
	return (NULL);
}
