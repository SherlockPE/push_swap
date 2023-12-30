/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_mv_pb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:28:01 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/30 16:06:41 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotar el numero encontrado hasta la cabecera y moverlo al stack B
static void	rotate_to_header(int position, t_list **stack_a, t_list **stack_b,
		int size)
{
	int	iterations;

	if (position < size / 2)
	{
		iterations = position;
		while (iterations--)
			rotate_a(stack_a);
	}
	else
	{
		iterations = size - position;
		while (iterations--)
			reverse_rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
}

// Encontrar un número que pertenezca al chunk actual
static void	found_position(t_list *stack_a, int *array, int separator,
		int *position)
{
	int	actual;

	while (stack_a)
	{
		actual = *(int *)(stack_a)->content;
		if (actual < array[separator])
			return ;
		(*position)++;
		stack_a = (stack_a)->next;
	}
}

static void	chunks_mv_pb(t_list **stack_a, t_list **stack_b, int *array,
		int separator)
{
	int	position;
	int	size;

	size = ft_lstsize(*stack_a);
	position = 0;
	found_position(*stack_a, array, separator, &position);
	rotate_to_header(position, stack_a, stack_b, size);
}

// Function separate the elements in chunks and it pushes to stack b
void	move_elements_to_sb(t_list **stack_a, t_list **stack_b, int separator,
		int *array)
{
	int	i;
	int	temp;
	int	size;

	temp = separator;
	size = ft_lstsize(*stack_a);
	while (size)
	{
		i = temp;
		while (i-- && size)
		{
			chunks_mv_pb(stack_a, stack_b, array, separator);
			size = ft_lstsize(*stack_a);
		}
		separator += temp;
		size = ft_lstsize(*stack_a);
	}
}

// void	rotatate_after_push(t_list	**stack_b, int	pivot)
// {
// 	// t_list	*header;
// 	int	actual;
// 	// int middle_value;
// 	// int	middle_position;

// 	//primera posición del stack_b
// 	actual = *(int *)(*stack_b)->content;

// 	//Obtener el valor de la posicion del medio de stack_b
// 	// middle_position = ft_lstsize(*stack_b) / 2;
// 	// header = *stack_b;
// 	// while (header && middle_position--)
// 	// {
// 	// 	middle_value = *(int *)header->content;
// 	// 	header = header->next;
// 	// }

// 	//Si el valor ingresante(actual) es menor que el valor del medio hacer ra
// 	if (actual > pivot && ft_lstsize(*stack_b) > 1)
// 		rotate_b(stack_b);
// }
