/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:37:16 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/12/30 17:39:16 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_upper_number_position(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (size > j)
	{
		if (array[i] > array[j])
			j++;
		else
		{
			i = j;
			j = i + 1;
		}
	}
	return (i + 1);
}

static int	rotate_operations_sb(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	iterations;
	int	position;
	int	*int_array;

	size = ft_lstsize(*stack_b);
	int_array = convert_to_int_array(*stack_b);
	if (!int_array)
		return (0);
	position = get_upper_number_position(int_array, ft_lstsize(*stack_b));
	if (position <= size / 2)
	{
		iterations = position - 1;
		while (iterations--)
			rotate_b(stack_b);
	}
	else
	{
		iterations = size - position + 1;
		while (iterations--)
			reverse_rotate_b(stack_b);
	}
	push_a(stack_a, stack_b);
	free(int_array);
	return (1);
}

static int	move_elements_to_sa(t_list **stack_a, t_list **stack_b)
{
	int	size_b;

	size_b = ft_lstsize(*stack_b);
	while (!is_it_order_yet(*stack_b, 2))
	{
		if (!rotate_operations_sb(stack_a, stack_b))
			return (0);
		size_b = ft_lstsize(*stack_b);
	}
	size_b = ft_lstsize(*stack_b);
	while (size_b--)
		push_a(stack_a, stack_b);
	return (1);
}

int	chunks_alg(t_list **stack_a, t_list **stack_b, int chunk_size)
{
	int	*array;
	int	size;
	int	separator;

	size = ft_lstsize(*stack_a);
	array = convert_to_int_array(*stack_a);
	if (!array)
		return (0);
	if (!merge_sort(array, size))
	{
		free(array);
		return (0);
	}
	separator = size / chunk_size;
	move_elements_to_sb(stack_a, stack_b, separator, array);
	if (!move_elements_to_sa(stack_a, stack_b))
	{
		free(array);
		return (0);
	}
	free(array);
	return (1);
}

// void	print_array(int	*array_1_D, int count)
// {
// 	printf("Array ordenado: \n");
// 	for (int i = 0; i < count; i++)
// 	{
// 		printf("%d\n", array_1_D[i]);
// 	}
// }