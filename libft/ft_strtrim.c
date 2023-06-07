/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:01:29 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/19 17:33:02 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stddef.h>
#include"libft.h"

static	int	ft_comp(char temp, char const *set)
{
	int	ans;
	int	i;

	i = 0;
	ans = 0;
	while (set[i] != '\0')
	{
		if (set[i] == temp)
			ans++;
		i++;
	}
	return (ans);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*ans;
	int		end;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] != '\0' && ft_comp(s1[i], set))
		i++;
	end = ft_strlen(s1);
	while (0 <= end && ft_comp(s1[end - 1], set))
		end--;
	if (end < i)
		return (ft_strdup(""));
	ans = malloc(sizeof(char) * (end - i + 1));
	if (ans == NULL)
		return (NULL);
	ft_strlcpy (ans, &s1[i], end - i + 1);
	return (ans);
}
