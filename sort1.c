/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:42:35 by ykawai            #+#    #+#             */
/*   Updated: 2023/05/21 19:48:15 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<limits.h>
#include"push_swap.h"
#include"ft_printf.h"

void	swap_top(t_Linked_list *stack)
{
	t_Linked_list	*top;
	t_Linked_list	*sentinel_node;

	if (stack -> type == 'a')
		ft_printf("sa\n");
	if (stack -> type == 'b')
		ft_printf("sb\n");
	top = stack -> next -> next;
	sentinel_node = stack;
	stack = stack -> next;
	sentinel_node -> next = top;
	top -> next -> prev = stack;
	top -> prev = sentinel_node;
	stack -> prev = top;
	stack -> next = top -> next;
	top -> next = stack;
}

void	go_bottom(t_Linked_list *stack)
{
	t_Linked_list	*top;
	t_Linked_list	*sentinel_node;

	if (stack -> type == 'a')
		ft_printf("ra\n");
	if (stack -> type == 'b')
		ft_printf("rb\n");
	sentinel_node = stack;
	top = stack -> next -> next;
	stack = stack -> next;
	top -> prev = sentinel_node;
	sentinel_node -> next = top;
	stack -> prev = sentinel_node -> prev;
	sentinel_node -> prev -> next = stack;
	stack -> next = sentinel_node;
	sentinel_node -> prev = stack;
}

void	go_top(t_Linked_list *stack)
{
	t_Linked_list	*top;
	t_Linked_list	*sentinel_node;

	if (stack -> type == 'a')
		ft_printf("rra\n");
	if (stack -> type == 'b')
		ft_printf("rrb\n");
	sentinel_node = stack;
	top = sentinel_node -> prev;
	top -> prev -> next = sentinel_node;
	sentinel_node -> prev = top -> prev;
	sentinel_node -> next -> prev = top;
	top -> next = sentinel_node -> next;
	top -> prev = sentinel_node;
	sentinel_node -> next = top;
}

t_Linked_list	*push_node(t_Linked_list *cut, t_Linked_list *push)
{
	t_Linked_list	*sentinel_node;
	t_Linked_list	*b_sentinel_node;

	if (push == NULL)
	{
		push = cut;
		b_sentinel_node = b_linked_lst_head();
		push -> next = b_sentinel_node;
		push -> prev = b_sentinel_node;
		b_sentinel_node -> prev = push;
		b_sentinel_node -> next = push;
		return (push);
	}
	sentinel_node = search_sentinelnode(push);
	cut -> next = push;
	push -> prev = cut;
	sentinel_node -> next = cut;
	cut -> prev = sentinel_node;
	return (cut);
}

void	cut_node(t_Linked_list *home, t_Linked_list *push)
{
	t_Linked_list	*home_sentinel_node;
	t_Linked_list	*push_sentinel_node;
	t_Linked_list	*push_top;
	t_Linked_list	*cut;

	if (home -> type == 'a')
		ft_printf("pa\n");
	if (home -> type == 'b')
		ft_printf("pb\n");
	home_sentinel_node = home;
	push_sentinel_node = push;
	cut = home -> next;
	push_top = push -> next;
	cut -> next -> prev = home_sentinel_node;
	home_sentinel_node -> next = cut -> next;
	cut -> next = push_top;
	push_top -> prev = cut;
	push_sentinel_node -> next = cut;
	cut -> prev = push_sentinel_node;
	push_sentinel_node -> next = cut;
}
