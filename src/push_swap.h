/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:03:18 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/30 17:09:16 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

// Push swap Utils
int		create_list(char **list_values, t_list **new_list);
void	print_listas(t_list *header_a, t_list *header_b);
int		error_content_size(t_list **stack);
int		ft_perror(char *message);

// Error cases
int		check_errors(int argc, char **argv);
int		repeat_numbers(t_list *new_list);
void	free_split(char **array);

// Operations
//      Swap (sa, sb, ss)
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_ss(t_list **stack_a, t_list **stack_b);

//      Push (pa, pb, )
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);

//      Rotate (ra, rb, rr)
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_rr(t_list **stack_a, t_list **stack_b);

//      Reverse rotate (rra, rrb, rrr)
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_rr(t_list **stack_a, t_list **stack_b);

// Plugin
void	enter_parameter(t_list **stack_a, t_list **stack_b);

// Algorithm
int		sort_list(t_list **stack_a, t_list **stack_b);

// Bubble sort algorithm
int		bubble_sort_algorithm(t_list **stack_a, t_list **stack_b);

// Chunks algorithm
int		chunks_alg(t_list **stack_a, t_list **stack_b, int chunk_size);
void	move_elements_to_sb(t_list **stack_a, t_list **stack_b, int separator,
			int *array);
// void	move_elements_to_sa(t_list **stack_a, t_list **stack_b, int size,
// int *array);
int		merge_sort(int *original_array, int size);

// Algorithm utils
int		get_lower_number_position(int *cadena, int size);
int		*convert_to_int_array(t_list *stack);
int		is_it_order_yet(t_list *stack, int order);
void	sort_5_cases(t_list **stack_a);

#endif