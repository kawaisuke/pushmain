/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:59:34 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/19 21:06:28 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include<stdlib.h>
#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (ft_strlen(&s[start]) + 1 < len)
		j = (ft_strlen(&s[start]) + 1);
	else
		j = len + 1;
	ans = malloc(sizeof(char) * j);
	if (ans == NULL)
		return (NULL);
	while (0 < start && *s != '\0')
	{
		s++;
		start--;
	}
	while (i < len && *s != '\0')
		ans[i++] = *s++;
	ans[i] = '\0';
	return (ans);
}
