/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_mv_pb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:28:01 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/23 15:35:14 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Rotar el numero encontrado hasta la cabecera y moverlo al stack B
static void	rotate_to_header(int position, t_list **stack_a, t_list **stack_b, int size)
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


//Encontrar un número que pertenezca al chunk actual
static void	found_position(t_list *stack_a, int *array, int separator, int *position)
{
	int	actual;

	printf("Valor de separator (chunk): %d\n", separator);
	while (stack_a)
	{
		actual = *(int *)(stack_a)->content;
		printf("Valor actual: %d\n", actual);
		printf("Position: %d\n\n", *position);
		if (actual < array[separator])
			return ;
		(*position)++;
		stack_a = (stack_a)->next;
	}
}

static void	chunks_mv_pb(t_list **stack_a, t_list **stack_b, int *array, int size, int separator)
{
	int	position;
	position = 0;

	found_position(*stack_a, array, separator, &position);
	rotate_to_header(position, stack_a, stack_b, size);
}

void    move_elements_to_sb(t_list **stack_a, t_list **stack_b, int size, int *array)
{
    int separator;
    int i;
    
    separator = size / 4;
	int temp = separator;
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