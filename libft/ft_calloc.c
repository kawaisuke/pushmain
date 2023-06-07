/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:54:34 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/18 10:55:58 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include<stdlib.h>
#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ans;
	size_t	check;
	size_t	s;

	check = count * size;
	if (size != 0)
	{
		s = check / size;
		if (s != count)
			return (NULL);
	}
	ans = malloc(size * count);
	if (ans == NULL)
		return (NULL);
	ft_bzero(ans, count * size);
	return (ans);
}
