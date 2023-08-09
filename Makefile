# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalbobak <aalbobak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 18:38:54 by aalbobak          #+#    #+#              #
#    Updated: 2023/08/09 19:52:02 by aalbobak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	push_swap.c split.c ft_atoi_atoil.c	init_fns.c \
					parsing2.c init_lst.c sort.c the_moves.c the_moves_r.c \
					sort1.c index.c sort_more.c sort2.c
OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g3 #-fsanitize=address

NAME			= push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
