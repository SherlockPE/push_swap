/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:28:35 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/08 14:49:26 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (!check_errors(argc, argv))
		printf("Error\n");
	else
	{
		create_list(argv, &stack_a);
		print_listas(stack_a, stack_b);
		
		sort_list(&stack_a, &stack_b);
		
		print_listas(stack_a, stack_b);
	}
	return (0);
}

// enter_parameter(&stack_a, &stack_b);
// if (!check_errors(argc, argv))
// {
// 	printf("Error\n");
// 	return (2);
// }
// else
// {
// 	create_list(argv, &stack_a);
// 	printf("Estado actual del stack_a\n");
// 	print_lista(stack_a);
// }

// Reverse rotate opeations (rra, rrb, rrr)
// reverse_rotate_a(&stack_a);
// printf("Estado actual del stack_a\n");
// print_lista(stack_a);

// reverse_rotate_b(&stack_a);
// printf("Estado actual del stack_a\n");
// print_lista(stack_a);

// reverse_rotate_rr(&stack_a, &stack_a);
// printf("Estado actual del stack_a\n");
// print_lista(stack_a);

// Rotate operations (ra, rb, rr);
// rotate_a(&stack_a);
// printf("Estado actual del stack_a\n");
// print_lista(stack_a);

// rotate_a(&stack_a);
// printf("Estado actual del stack_a\n");
// print_lista(stack_a);

// rotate_a(&stack_a);
// printf("Estado actual del stack_a\n");
// print_lista(stack_a);

// Push operations (pa, pb)
// //pb pb pb
// push_b(&stack_a, &stack_b);
// push_b(&stack_a, &stack_b);
// push_b(&stack_a, &stack_b);
// printf("Estado actual del stack_a\n");
// print_lista(stack_a);

// printf("Estado actual del stack_b\n");
// print_lista(stack_b);

// //pa pa
// push_a(&stack_a, &stack_b);
// push_a(&stack_a, &stack_b);

// printf("Estado actual del stack_a\n");
// print_lista(stack_a);

// printf("Estado actual del stack_b\n");
// print_lista(stack_b);

// Swap operations (sa, sb, ss)
// swap_a(&stack_a);
// print_lista(stack_a);
// swap_b(&stack_a);
// print_lista(stack_a);
// swap_ss(&stack_a, &stack_a);