# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 16:58:57 by flopez-r          #+#    #+#              #
#    Updated: 2023/12/30 16:52:06 by flopez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = src/push_swap_utils.c \
	src/push_swap.c \
	src/operations_swap.c \
	src/operations_push.c \
	src/operations_rotate.c \
	src/operations_reverse_rotate.c \
	src/push_swap_utils.c \
	src/algorithm.c \
	src/algorithm_utils.c \
	src/error_cases.c \
	src/bubble_sort.c \
	src/chunks_algorithm.c \
	src/merge_sort.c \
	src/chunks_mv_pb.c
OBJ = $(SRC:.c=.o)
CC := gcc
CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $^ -L./Libft -lft -o $@


clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ)
# rm -f $(OBJ) $(BNS_OBJS)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


#	$(MAKE) es una variable globar
# 			-C <directorio donde hará make>
#	si quiero una regla específica








# 			<regla del makefile> -C <directorio donde hará make>
#-L --> especificar directorio --> -L<name_directory>
#-l  --> nombre de la libreria --> -l<nombre de la libreria> (no se pone lib porque es un estandar)



# gcc -W push_swap.c -ILibft/ -LLibft/ -lft