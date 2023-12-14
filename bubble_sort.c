/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:59:21 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/14 17:17:16 by flopez-r         ###   ########.fr       */
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

	(void)stack_b;
	int_array = convert_to_int_array(*stack_a);

	
	int i = 0;
	int size = ft_lstsize(*stack_a);
	while (i < size)
	{
		printf("%d, ", int_array[i]);
		i++;
	}

	position = get_lower_number_position(int_array, ft_lstsize(*stack_a));
	printf("\nThe lower number is in the position: %d\n", position);
	printf("The size of the stack is: %d", size);
	return (1);
}