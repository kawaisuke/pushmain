/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:53:01 by ykawai            #+#    #+#             */
/*   Updated: 2023/05/22 20:22:42 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<limits.h>
#include"push_swap.h"
#include"ft_printf.h"

/* */
int	count_stack(int judge, t_Linked_list *a_stack)
{
	int	count;

	count = 1;
	a_stack = a_stack -> next;
	while (a_stack -> score != judge)
	{
		a_stack = a_stack -> next;
		count++;
	}
	return (count);
}

void	three_stack_sort(t_Linked_list *stack)
{
	int	top;
	int	second;
	int	third;

	top = stack -> next -> score;
	second = stack -> next -> next -> score;
	third = stack -> next -> next -> next -> score;
	if (top < second && second > third && third > top) /*1 3 2*/
	{
		swap_top(stack);
		go_bottom(stack);
	}
	else if (top > second && second < third && third > top) //2 1 3
		swap_top(stack);
	else if (top < second && second > third && third < top) //2 3 1
		go_top(stack);
	else if (top > second && second < third && third < top) //3 1 2
		go_bottom(stack);
	else if (top > second && second > third && third < top) /* 3 2 1 */
	{
		swap_top(stack);
		go_top(stack);
	}
}

void	under_six_sort(int search, t_Linked_list *a_stack, t_Linked_list *b_stack)
{
	int	min;
	int	judge;

	judge = 0;
	min = a_stack -> next -> score;
		a_stack = a_stack -> next;
	while (a_stack -> value >= INT_MIN)
	{
		if (min > a_stack -> score)
			min = a_stack -> score;
		a_stack = a_stack -> next;
		judge++;
	}
	if (count_stack(min, a_stack) <= judge / 2)
		while (a_stack -> next -> score != min)
			go_bottom(a_stack);
	else
		while (a_stack -> next -> score != min)
			go_top(a_stack);
	cut_node(a_stack, b_stack);
	search--;
	if (search != 0)
		under_six_sort(search, a_stack, b_stack);
	three_stack_sort(a_stack);
	cut_node(b_stack, a_stack);
}

void	less_sort(t_Linked_list *a_stack, t_Linked_list *b_stack)
{
	int	count;

	count = 1;
	a_stack = a_stack -> next;
	while (a_stack -> next -> value >= INT_MIN)
	{
		a_stack = a_stack -> next;
		count++;
	}
	a_stack = a_stack -> next;
	ft_printf("value = %d\n",a_stack -> value);
	if (count == 2)
		swap_top(a_stack);
	else if (count == 3)
		three_stack_sort(a_stack);
	else if (count == 4)
		under_six_sort(1, a_stack, b_stack);
	else if (count == 5)
		under_six_sort(2, a_stack, b_stack);
	else if (count == 6)
		under_six_sort(3, a_stack, b_stack);
}
