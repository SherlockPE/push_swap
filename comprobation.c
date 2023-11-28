/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprobation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:11:32 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/28 15:06:57 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// void	imprimir(char **operations)
// {
// 	int	i;

// 	i = 0;
// 	while (operations[i])
// 	{
// 		printf("%s\n", operations[i]);
// 		i++;
// 	}
// }

int	check_answer(char *response, t_list **stack_a, t_list **stack_b, int *contador)
{
	int	i;

	(*contador)++;
	i = 0;
	if (!ft_strncmp(response, "sa", 2))
		swap_a(stack_a);
	else if (!ft_strncmp(response, "sb", 2))
		swap_b(stack_b);
	else if (!ft_strncmp(response, "ss", 2))
		swap_ss(stack_a, stack_b);
	else if (!ft_strncmp(response, "pa", 2))
		push_a(stack_a, stack_b);
	else if (!ft_strncmp(response, "pb", 2))
		push_b(stack_a, stack_b);
	else if (!ft_strncmp(response, "ra", 2))
		rotate_a(stack_a);
	else if (!ft_strncmp(response, "rb", 2))
		rotate_b(stack_b);
	else if (!ft_strncmp(response, "rr", 2))
		rotate_rr(stack_a, stack_b);
	else if (!ft_strncmp(response, "rra", 2))
		reverse_rotate_a(stack_a);
	else if (!ft_strncmp(response, "rrb", 2))
		reverse_rotate_b(stack_b);
	else if (!ft_strncmp(response, "rra", 2))
		reverse_rotate_rr(stack_a, stack_b);
	else if (!ft_strncmp(response, "q", 1))
		return (0);
	return (1);
}

	// char *operations[12] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
	// 	"rra", "rrb", "rrr", "\0"};
void	enter_parameter(t_list **stack_a, t_list **stack_b)
{
	// char	*answer;
	// int		count_operations;
	// while (1)
	// {
	printf("Ingresa un argumento:\n");
	printf("sa\nsb\nss\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr\n");
		// scanf(&answer);
		// if (!check_answer(answer, stack_a, stack_b, &count_operations))
		// {
		// 	printf("Cantidad de operaciones: %d\n", count_operations - 1);
		// 	return ;
		// }
		
	print_listas(*stack_a, *stack_b);
	// }
}