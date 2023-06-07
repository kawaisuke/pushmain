/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:37:57 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/20 13:25:20 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	uc;
	unsigned char	*p;

	uc = (unsigned char)ch;
	p = (unsigned char *)buf;
	while (0 < n)
	{
		*p = uc;
		p++;
		n--;
	}
	return (buf);
}
