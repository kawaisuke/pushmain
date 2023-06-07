/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_error_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:41:52 by ykawai            #+#    #+#             */
/*   Updated: 2023/05/21 20:49:03 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"
#include"limits.h"
#include"push_swap.h"
#include"ft_printf.h"

int	sort_checker(t_Linked_list *stack)
{
	long	now;
	long	prev;

	while (stack -> next -> value >= INT_MIN)
	{
		now = stack -> score;
		prev = stack -> next -> score;
		if (now > prev)
			return (0);
		if (now == prev)
			return (ERROR_END);
		stack = stack -> next;
	}
	return (SORTED);
}

int	same_checker(t_Linked_list *stack)
{
	t_Linked_list	*tmp;
	long			now;
	long			after;

	stack = stack -> next;
	while (stack -> next ->value >= INT_MIN)
	{
		now = stack -> score;
		tmp = stack -> next;
		while (tmp -> value >= INT_MIN)
		{
			after = tmp -> score;
			if (after == now)
				return (ERROR_END);
			tmp = tmp -> next;
		}
		stack = stack -> next;
	}
	return (0);
}

t_Linked_list	*search_sentinelnode(t_Linked_list *home)
{
	t_Linked_list	*sentinel_node;

	if (home -> value < INT_MIN)
		return (home);
	sentinel_node = home -> next;
	while (sentinel_node -> value >= INT_MIN)
		sentinel_node = sentinel_node -> next;
	return (sentinel_node);
}

void	linked_lst_freee(t_Linked_list *stack)
{
	t_Linked_list	*tmp;

	while (stack -> value >= INT_MIN)
	{
		tmp = stack -> next;
		free(stack);
		stack = tmp;
	}
}
