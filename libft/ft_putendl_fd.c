/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:39:44 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/19 19:30:38 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include"libft.h"
#include<stddef.h>

void	ft_putendl_fd(char *s, int fd)
{
	char	*c;

	if (s == NULL)
		return ;
	c = "\n";
	write(fd, s, ft_strlen(s));
	write(fd, c, 1);
}
