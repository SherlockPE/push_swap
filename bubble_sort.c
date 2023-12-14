/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:59:21 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/14 20:05:17 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lower_number_position(int *cadena, int size)
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

int	*convert_to_int_array(t_list *stack)
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

int	bubble_sort_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	position;
	int *int_array;
	int iterations;
	int size_b;
	int size;
	

	(void)stack_b;
	size = ft_lstsize(*stack_a);

	while (!is_it_order_yet(*stack_a, 1))
	{
		int_array = convert_to_int_array(*stack_a);
		position = get_lower_number_position(int_array, ft_lstsize(*stack_a));
		printf("Value %d - Position %d\n", int_array[position - 1], position);
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
		print_listas(*stack_a, *stack_b);
	}
	size_b = ft_lstsize(*stack_b);
	while (size_b--)
		push_a(stack_a, stack_b);

	// printf("\nThe lower number is in the position: %d\n", position);
	// printf("The value of middle is: %d\n", size / 2);
	// printf("The size of the stack is: %d\n", size);
	
	return (1);
}