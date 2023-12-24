/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_mv_pb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:28:01 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/24 10:07:05 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	rotatate_after_push(t_list	**stack_b)
// {
// 	int	size_b = ft_lstsize(*stack_b);
// 	if (size_b % 2 == 0)
// 		rotate_b(stack_b);
// 	else
// 		reverse_rotate_b(stack_b);
// }

// Rotar el numero encontrado hasta la cabecera y moverlo al stack B
static void	rotate_to_header(int position, t_list **stack_a, t_list **stack_b,	int size)
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
	//rotatate_after_push(stack_b);
}

// Encontrar un número que pertenezca al chunk actual
static void	found_position(t_list *stack_a, int *array, int separator,
		int *position)
{
	int	actual;

	// printf("Valor de separator (chunk): %d\n", separator);
	while (stack_a)
	{
		actual = *(int *)(stack_a)->content;
		// printf("Valor actual: %d\n", actual);
		// printf("Position: %d\n\n", *position);
		if (actual < array[separator])
			return ;
		(*position)++;
		stack_a = (stack_a)->next;
	}
}

static void	chunks_mv_pb(t_list **stack_a, t_list **stack_b, int *array,
		int size, int separator)
{
	int	position;

	position = 0;
	found_position(*stack_a, array, separator, &position);
	rotate_to_header(position, stack_a, stack_b, size);
}

// Function separate the elements in chunks and it pushes to stack b
void	move_elements_to_sb(t_list **stack_a, t_list **stack_b, int separator, int *array)
{
	int i;
	int	temp;
	int	size;

	temp = separator;
	size = ft_lstsize(*stack_a);
	while (size)
	{
		i = temp;
		while (i-- && size)
		{
			chunks_mv_pb(stack_a, stack_b, array, ft_lstsize(*stack_a), separator);
			size = ft_lstsize(*stack_a);
		}
		separator += temp;
		size = ft_lstsize(*stack_a);
	}
}
