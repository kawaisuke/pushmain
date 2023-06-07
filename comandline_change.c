/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandline_change.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:50:10 by ykawai            #+#    #+#             */
/*   Updated: 2023/05/21 20:51:20 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include"libft.h"
#include"limits.h"
#include"ft_printf.h"
#include"push_swap.h"

t_Linked_list	*comandline_change(t_Linked_list	*stack, char	*str)
{
	t_Linked_list	*ans;

	ans = linked_lstnew((ft_atoi(str)));
	linked_lstadd_back(stack, ans);
	return (stack);
}

void	cordinate_compression(t_Linked_list *stack)
{
	long			now;
	long			prev;
	long			count;
	t_Linked_list	*tmp;

	stack = stack -> next ;
	while (stack -> value >= INT_MIN)
	{
		count = 0;
		now = stack -> value;
		tmp = stack -> next;
		while (tmp != stack)
		{
			prev = tmp -> value;
			if (now > prev)
				count++;
			tmp = tmp -> next;
		}
		stack -> score = count;
		stack = stack -> next;
	}
}
