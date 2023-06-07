/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:18:17 by ykawai            #+#    #+#             */
/*   Updated: 2023/05/22 20:23:43 by ykawai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

#define PUSH_SWAP_H

#define ERROR_END -1
#define SORTED -2
#define NOT_FOUND -3
typedef struct s_Linked_list
{
	long	value;
	long	score;
	char	type;
	struct s_Linked_list* next;
	struct s_Linked_list* prev;

}	t_Linked_list;

void	linked_lst_addlast(t_Linked_list *front);
void ft_output(t_Linked_list *stack);//atodekesu
int		non_integer(char *str);
int		same_checker(t_Linked_list *stack);
int		error_end(char *str);
t_Linked_list *linked_lst_head(void);//atodehensyu dekita?
t_Linked_list	*linked_lstnew(int argc);
t_Linked_list *comandline_change(t_Linked_list *stack,char *str);
void linked_lstadd_back(t_Linked_list *front, t_Linked_list *back);
void linked_lst_freee(t_Linked_list *stack);
void		cordinate_compression(t_Linked_list *stack);
int		sort_checker(t_Linked_list *stack);
void swap_top(t_Linked_list *stack);
void	go_bottom(t_Linked_list *stack);
void	go_top(t_Linked_list *stack);
void	cut_node(t_Linked_list *home,t_Linked_list *push);

void ft_output_score(t_Linked_list *stack);//atodekesu
t_Linked_list *b_linked_lst_head(void);//atodehensyu dekita?;
t_Linked_list	*search_sentinelnode(t_Linked_list *home);
t_Linked_list	*search_sentinelnode(t_Linked_list *home);
void less_sort(t_Linked_list *a_stack, t_Linked_list *b_stack);
void	linked_lst_freee(t_Linked_list *stack);

void	lot_sort(t_Linked_list *a_stack, t_Linked_list *b_stack);
#endif 

