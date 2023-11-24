# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 16:58:57 by flopez-r          #+#    #+#              #
#    Updated: 2023/11/24 11:57:32 by flopez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = push_swap_utils.c push_swap.c operations_swap.c operations_push.c
OBJ = $(SRC:.c=.o)
CC := gcc
CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $^ -L. -lft -o $@


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