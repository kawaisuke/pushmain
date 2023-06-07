/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:34:16 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/19 16:16:36 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include"libft.h"
#include<stddef.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ans = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +1));
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ans[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ans[i + j] = s2[j];
		j++;
	}
	ans[i + j] = '\0';
	return (ans);
}
