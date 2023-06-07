/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:04:19 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/19 19:20:52 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (haystack == NULL && len == 0)
		return (NULL);
	if (*needle == '\0')
		return ((char *) haystack);
	while (*haystack != '\0' && 0 < len)
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i] != '\0' && i < len)
			i++;
		if (needle[i] == '\0')
			return ((char *) haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
