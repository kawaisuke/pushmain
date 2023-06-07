/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:29:04 by ykawai            #+#    #+#             */
/*   Updated: 2023/01/18 12:29:18 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include"libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tem;

	tem = lst;
	while (tem != NULL)
	{
		lst = tem;
		tem = lst -> next;
	}
	return (lst);
}
