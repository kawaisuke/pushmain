#include"unistd.h"
#include"push_swap.h"
#include"libft.h"
#include"ft_printf.h"

//#include <libc.h>
//
//__attribute__((destructor))
//static void destructor() {
//    system("leaks -q push_swap");
//}


int main(int argc, char **argv)
{
	int i;
	t_Linked_list	*a_stack;
	t_Linked_list	*b_stack;

	b_stack = b_linked_lst_head();
	i = 1;
	if (argc < 2)
		return (0);
	while(argv[i])
	{
		if (error_end(argv[i]))
			return (0);
		i++;
	}

	i = 1;
	a_stack = linked_lst_head();
	while(argv[i])
	{
		a_stack = comandline_change(a_stack,argv[i]);
		i++;
	}
	linked_lstadd_back(a_stack,search_sentinelnode(a_stack));
//ft_printf("good\n");
//	ft_output(a_stack);
//	ft_printf(" 座標圧縮\n");
//
//	ft_printf(" 座標圧縮\n");
	cordinate_compression(a_stack);
//	ft_output_score(a_stack);
	if( -1 ==same_checker(a_stack) )
		return(ft_printf("ERROREND"));
	if( sort_checker(a_stack) )
	{
		return (ft_printf("END\n"));
//	linked_lst_freee(a_head.next);//a_stack);
//		return (0);
	}
	if (argc <= 7)
		less_sort(a_stack,b_stack);
	if( sort_checker(a_stack) )
	{
		ft_output(a_stack);
		return (ft_printf("END\n"));
//	linked_lst_freee(a_head.next);//a_stack);
//		return (0);
	}
	ft_printf("a_stack\n");
	ft_output(a_stack);
	lot_sort(a_stack,b_stack);//開発中まだ未完成
	ft_printf("a dayo\n");
	ft_output(a_stack);
	ft_printf("b dayo\n");
	ft_output(b_stack);
////	linked_lst_freee(b_stack);//a_stack);
}
