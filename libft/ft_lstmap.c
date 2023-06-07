/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:29:22 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/20 19:59:10 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ans;
	t_list	*new;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	ans = NULL;
	while (lst != NULL)
	{
		new = (ft_lstnew((*f)(lst-> content)));
		if (new == NULL)
		{
			ft_lstclear(&ans, (*del));
			return (NULL);
		}
		ft_lstadd_back(&ans, new);
		lst = lst -> next;
	}
	return (ans);
}
