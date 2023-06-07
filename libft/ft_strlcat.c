/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:57:17 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/20 13:34:13 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>

static size_t	len_str(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	k;
	size_t	max_copy;
	size_t	d_nb;
	size_t	s_nb;

	s_nb = len_str(src);
	if (size == 0)
		return (s_nb);
	d_nb = len_str(dest);
	if (size <= d_nb)
		return (size + s_nb);
	max_copy = size - d_nb - 1;
	k = 0;
	while (k < max_copy)
	{
		if (src[k] == '\0')
			break ;
		dest[d_nb + k] = src[k];
		k++;
	}
	dest[k + d_nb] = '\0';
	return (s_nb + d_nb);
}
