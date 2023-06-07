/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:07:19 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/18 12:08:38 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char		*p;
	char			*a;
	unsigned char	uc;
	int				i;

	p = (const char *)s;
	a = (char *)p;
	uc = (unsigned char)c;
	i = 0;
	while (p[i] != '\0')
		i++;
	while (0 <= i)
	{
		if (a[i] == uc)
			return (&a[i]);
		i--;
	}
	return (NULL);
}
