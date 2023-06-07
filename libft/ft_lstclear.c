/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:27:11 by ykawai            #+#    #+#             */
/*   Updated: 2023/05/13 12:51:27 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tem;

	if (del == NULL || lst == NULL)
		return ;
	while (*lst != NULL)
	{
		tem = (*lst)->next;
		(*del)((*lst)->content);
		(*lst)-> next = NULL;
		free(*lst);
		*lst = tem;
	}
}
