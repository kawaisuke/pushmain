#include"libft.h"
#include"push_swap.h"
#include<limits.h>
#include"ft_printf.h"

void ft_output(t_Linked_list *stack)
{
	stack = stack -> next;
	while (stack -> value >= INT_MIN)// head < 1)
	{
		ft_printf("%d\n",stack -> value);
		stack  = stack -> next; 
	}
//	stack = stack -> next;
}

//atodekesu
void ft_output_score(t_Linked_list *stack)
{
	stack = stack -> next;
	while (stack -> value >= INT_MIN)
	{
	//ft_printf("hazime?\n");
		ft_printf("%d\n",stack -> score);
		stack  = stack -> next; 
	}
//	stack = stack -> next;


}

//void	sa_sb_output(t_Linked_list *stack,char a)
//{
//	if (a == 'a')
//	{
//		ft_printf("sa\n");
//		swap_top(stack);
//	}
//	if (a == 'b')
//	{
//		ft_printf("sb\n");
//		swap_top(stack);
//	}
//}
//void	ra_sb_output(t_Linked_list *stack,char a)
//{
//	if (a == 'a')
//	{
//		ft_printf("sa\n");
//		swap_top(stack);
//	}
//	if (a == 'b')
//	{
//		ft_printf("sb\n");
//		swap_top(stack);
//	}
//}
//void	sa_sb_output(t_Linked_list *stack,char a)
//{
//	if (a == 'a')
//	{
//		ft_printf("sa\n");
//		swap_top(stack);
//	}
//	if (a == 'b')
//	{
//		ft_printf("sb\n");
//		swap_top(stack);
//	}
//}
//void	sa_sb_output(t_Linked_list *stack,char a)
//{
//	if (a == 'a')
//	{
//		ft_printf("sa\n");
//		swap_top(stack);
//	}
//	if (a == 'b')
//	{
//		ft_printf("sb\n");
//		swap_top(stack);
//	}
//}
