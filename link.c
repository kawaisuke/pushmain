/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:44:00 by ykawai            #+#    #+#             */
/*   Updated: 2023/05/21 20:47:33 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"push_swap.h"
#include<stdlib.h>
#include<stddef.h>
#include<limits.h>

t_Linked_list	*linked_lstnew(int argc)
{
	t_Linked_list	*ans;

	ans = malloc(sizeof(t_Linked_list));
	if (ans == NULL)
		return (NULL);
	ans -> value = argc;
	ans -> score = 0;
	ans -> type = '\0';
	ans -> next = NULL;
	ans -> prev = NULL;
	return (ans);
}

t_Linked_list	*b_linked_lst_head(void)
{
	t_Linked_list	*ans;

	ans = malloc(sizeof(t_Linked_list));
	if (ans == NULL)
		return (NULL);
	ans -> value = (long)INT_MIN - (long)2;
	ans -> score = 0;
	ans -> type = 'b';
	ans -> next = ans;
	ans -> prev = ans;
	return (ans);
}

t_Linked_list	*linked_lst_head(void)
{
	t_Linked_list	*ans;

	ans = malloc(sizeof(t_Linked_list));
	if (ans == NULL)
		return (NULL);
	ans -> value = (long)INT_MIN - (long)2;
	ans -> score = 0;
	ans -> type = 'a';
	ans -> next = NULL;
	ans -> prev = NULL;
	return (ans);
}

void	linked_lstadd_back(t_Linked_list *front, t_Linked_list *back)
{
	if (front == NULL || back == NULL)
		return ;
	while (front -> next)
		front = front -> next;
	front -> next = back;
	back -> prev = front;
	return ;
}

void	linked_lst_addlast(t_Linked_list *front)
{
	t_Linked_list	*tmp;

	tmp = front;
	if (front == NULL)
		return ;
	while (front -> next)
		front = front -> next;
	front -> next = tmp;
	tmp -> prev = front;
	front = tmp;
	return ;
}
