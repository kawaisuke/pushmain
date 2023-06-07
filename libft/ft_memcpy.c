/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai </var/mail/ykawai>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:16:42 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/20 16:34:19 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s_dst;
	unsigned char	*s_src;

	if (src == NULL && dst == NULL)
		return (NULL);
	s_dst = (unsigned char *)dst;
	s_src = (unsigned char *)src;
	i = 0;
	while (0 < n)
	{
		s_dst[i] = s_src[i];
		i++;
		n--;
	}
	return (dst);
}
