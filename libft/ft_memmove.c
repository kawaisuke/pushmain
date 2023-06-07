/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:37:45 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/19 14:46:51 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*s_dst;
	unsigned char	*s_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	s_dst = (unsigned char *) dst;
	s_src = (unsigned char *) src;
	i = 0;
	if (dst > src)
	{
		while (0 < len--)
		{
			s_dst[len] = s_src[len];
		}
	}
	else
	{
		while (0 < len--)
		{
			s_dst[i] = s_src[i];
			i++;
		}
	}
	return (dst);
}
