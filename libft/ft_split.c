/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:25:59 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/21 18:26:05 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

static	int	ft_scspn(char const *s, char to_find)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == to_find)
			return (i);
		i++;
	}
	return (i);
}

static	int	count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	if (c == '\0')
		return (1);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			count++;
		if (s[i] == '\0')
			return (count);
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static void	ft_free(char **p, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(p[i]);
		i++;
	}
	free(p);
}

static	char	*ft_copy(int length, char const *s, char **p, int j)
{
	int		i;
	char	*copy;

	copy = malloc(sizeof(char) * (length + 1));
	if (copy == NULL)
	{
		ft_free(p, j);
		return (NULL);
	}
	i = 0;
	while (i < length)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**p;
	int		start;
	int		end;

	if (s == NULL)
		return (NULL);
	start = 0;
	j = 0;
	p = malloc (sizeof(char *) * (count(s, c) + 1));
	if (p == NULL)
		return (NULL);
	while (j < count(s, c))
	{
		end = start + ft_scspn(&s[start], c);
		if ((end - start) != 0)
		{
			p[j] = ft_copy((end - start), &s[start], p, j);
			if (p[j++] == NULL)
				return (NULL);
		}
		start = end + 1;
	}
	p[count(s, c)] = NULL;
	return (p);
}
