/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:42:35 by ykawai            #+#    #+#             */
/*   Updated: 2023/06/04 17:42:41 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<limits.h>
#include"push_swap.h"
#include"ft_printf.h"

int	number_stack(t_Linked_list *a_stack)
{
	int	i;

	i = 0;
	a_stack = a_stack -> next;
	while(a_stack -> value >= INT_MIN)
	{
		i++;
		a_stack = a_stack -> next;
	}
	return (i);
}

int	search_sort(int	small,int	top,t_Linked_list *a_stack)
{
	int	sort_count;
	int	i;
	int	find;

	i = 0;
	find = 0;
	a_stack = a_stack -> next;
	sort_count = number_stack(a_stack);
//	ft_printf("small = %d \n",small);
//	ft_printf("top = %d \n",top);
	while (a_stack -> value >= INT_MIN)//指定の値があるかどうか探すj
	{
		if (a_stack -> score <= top && small <= a_stack -> score)
		{
			find = a_stack -> score;
			break;
		}
		a_stack = a_stack -> next;
		i++;
	}
//	ft_printf("find = %d\n",find);
	//ft_printf("a_stack = %d\n",a_stack -> value);
	if (a_stack -> value < INT_MIN)
		return (NOT_FOUND);
	while (a_stack -> value >= INT_MIN)//番兵のーどまで戻す
		a_stack = a_stack -> next;
//	ft_printf("i = %d \n",i);
//	ft_printf("a_stack = %d\n",a_stack -> value);
	if (sort_count / 2 < i)
		while (a_stack -> next ->score != find)
			go_top(a_stack);
	else
		while (a_stack -> next ->score != find)
			go_bottom(a_stack);
//	ft_printf("find a_stack = \n");
//		ft_output(a_stack);
//	else
//		while (a_stack -> next ->score != find)
//			go_bottom(a_stack);
	return (0);
}

//void	small_push(int	small,int	top,t_Linked_list *a_stack, t_Linked_list *b_stack)
//{
//	cut_node(a_stack,b_stack);
//
//}

serach_min //一番小さいのを探してa_stackに一つずつ入れる	(	small,int	top,t_Linked_list *a_stack)

void	lot_sort(t_Linked_list *a_stack, t_Linked_list *b_stack)
{
//	t_Linked_list	*home_sentinel_node;
//	t_Linked_list	*push_sentinel_node;
//	t_Linked_list	*push_top;
//	t_Linked_list	*cut;
	int	i;

	i = number_stack(a_stack);
	while(1) 
	{
	if (search_sort(1,i/3 * 2, a_stack) == NOT_FOUND)
		break;
	cut_node(a_stack,b_stack);
	}
	while(1) 
	{
	if (search_sort(i/3 * 2 + 1, i, a_stack) == NOT_FOUND)
		break;
	cut_node(a_stack,b_stack);
	}
}
