/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:03:18 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/12 12:07:08 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

// Push swap Utils
int		is_it_int(char **array);
int		check_errors(int argc, char **argv);
void	create_list(char **list_values, t_list **new_list);
void	print_listas(t_list *header_a, t_list *header_b);
int		error_content_size(t_list **stack);

// Swap (sa, sb, ss)
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_ss(t_list **stack_a, t_list **stack_b);

// Push (pa, pb, )
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);

// Rotate (ra, rb, rr)
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_rr(t_list **stack_a, t_list **stack_b);

// Reverse rotate (rra, rrb, rrr)
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_rr(t_list **stack_a, t_list **stack_b);

// Plugin
void	enter_parameter(t_list **stack_a, t_list **stack_b);

// Algoritmo
void	sort_list(t_list **stack_a, t_list **stack_b);
int		is_it_order_yet(t_list *stack, int order);
void	sort_5_cases(t_list **stack_a, int *count);
// void    sort_5_cases(t_list **stack_a);

#endif