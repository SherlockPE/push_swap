/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:28:35 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/21 19:25:19 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	if (!check_errors(argc, argv))
		return(ft_perror("Error\n"));
	else
	{
		if (!create_list(argv, &stack_a))
			return (0);
		if (!stack_a)
			return (ft_perror("Error\n"));
		// print_listas(stack_a, stack_b);
		if (!sort_list(&stack_a, &stack_b))
			return (0);
		// print_listas(stack_a, stack_b);
	}
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}

// print_listas(stack_a, stack_b);
// print_listas(stack_a, stack_b);

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