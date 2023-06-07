# **************************************************************************** #
#                                                                              # #                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykawai <ykawai@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 19:36:37 by ykawai            #+#    #+#              #
#    Updated: 2023/05/01 20:38:17 by ykawai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CCFLAGS = -I $(LIBFT_PATH)

SRCS = push_swap.c error_handling.c link.c comandline_change.c ft_output.c after_error_handling.c sort1.c \
	   sort2.c \
	   lot_sort.c

OBJS = $(SRCS:.c=.o)


LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

BONUS_OBJS = $(BONUS:.c=.o)
NAME = push_swap


$(NAME):$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CCFLAGS)   $(OBJS)  $(LIBFT) -o $(NAME)

$(LIBFT):$(FORCE)
	make -C $(LIBFT_PATH)

FORCE:

all: $(NAME)


bonus: .bonus 

.c.o:
	$(CC) $(CFLAGS) $(CCFLAGS) -c  $<  -o $@


clean:
	rm -f $(OBJS) 
	make fclean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:clean fclean re all bonus
