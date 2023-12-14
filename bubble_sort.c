/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:59:21 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/14 20:44:22 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_lower_number_position(int *cadena, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (size > j)
	{
		if (cadena[i] < cadena[j])
			j++;
		else
		{
			i = j;
			j = i + 1;
		}
	}
	return (i + 1);
}

static int	*convert_to_int_array(t_list *stack)
{
	int i;
	int *int_array;

	int_array = (int *)calloc(ft_lstsize(stack), sizeof(int *));
	if (!int_array)
		return (0);
	i = 0;
	while (stack)
	{
		int_array[i++] = *(int *)stack->content;
		stack = stack->next;
	}
	return (int_array);
}

static void	rotate_operations(t_list **stack_a, t_list **stack_b)
{
	int size;
	int iterations;
	int	position;
	int *int_array;

	size = ft_lstsize(*stack_a);
	int_array = convert_to_int_array(*stack_a);
	position = get_lower_number_position(int_array, ft_lstsize(*stack_a));

	if (position <= size / 2)
	{
		iterations = position - 1;
		while (iterations--)
			rotate_a(stack_a);
	}
	else
	{
		iterations = size - position + 1;
		while (iterations--)
			reverse_rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
}

int	bubble_sort_algorithm(t_list **stack_a, t_list **stack_b)
{
	int size_b;
	
	while (!is_it_order_yet(*stack_a, 1))
		rotate_operations(stack_a, stack_b);
	size_b = ft_lstsize(*stack_b);
	while (size_b--)
		push_a(stack_a, stack_b);
	return (1);
}
