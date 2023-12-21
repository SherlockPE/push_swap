/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:59:21 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/21 18:36:46 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_operations(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	iterations;
	int	position;
	int	*int_array;

	size = ft_lstsize(*stack_a);
	int_array = convert_to_int_array(*stack_a);
	if (!int_array)
		return (0);
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
	free(int_array);
	return (1);
}

// Function found the smallest number in a list and then it moved to stackB
// then, when it finished, do PA
int	bubble_sort_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*stack_a);
	while (!is_it_order_yet(*stack_a, 1) && size_a > 3)
	{
		if (!rotate_operations(stack_a, stack_b))
			return (0);
		size_a = ft_lstsize(*stack_a);
	}
	while (!is_it_order_yet(*stack_a, 1))
		sort_5_cases(stack_a);
	size_b = ft_lstsize(*stack_b);
	while (size_b--)
		push_a(stack_a, stack_b);
	return (1);
}
