/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plugin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:11:32 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/28 18:03:48 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	check_answer(char *response, t_list **stack_a, t_list **stack_b,
		int *contador)
{
	int	i;

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
	else if (!ft_strncmp(response, "rra", 3))
		reverse_rotate_a(stack_a);
	else if (!ft_strncmp(response, "rrb", 3))
		reverse_rotate_b(stack_b);
	else if (!ft_strncmp(response, "rrr", 3))
		reverse_rotate_rr(stack_a, stack_b);
	else if (!ft_strncmp(response, "q", 1))
		return (0);
	else
		return (2);
	(*contador)++;
	return (1);
}

void	enter_parameter(t_list **stack_a, t_list **stack_b)
{
	char	answer[20];
	int		count_operations;
	int		result;

	count_operations = 0;
	while (1)
	{
		printf("Cantidad de operaciones: %d\n", count_operations);
		printf("Nota: Puedes presionar (q) para salir\n");
		printf("Ingresa un argumento: ");
		// printf("sa\nsb\nss\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr\n");
		scanf("%s", answer);
		system("clear");
		result = check_answer(answer, stack_a, stack_b, &count_operations);
		if (!result)
		{
			printf("Cantidad de operaciones: %d\n", count_operations - 1);
			return ;
		}
		else if (result == 2)
			printf("Ingresa un argumento válido!\n");
		print_listas(*stack_a, *stack_b);
	}
}
