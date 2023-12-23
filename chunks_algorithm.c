/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:37:16 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/12/23 15:10:47 by flopez-r         ###   ########.fr       */
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

static void	chunks_function(t_list **stack_a, t_list **stack_b, int *array_1_D, int size, int separator)
{
	int	position;
	position = 0;

	found_position(*stack_a, array_1_D, separator, &position);
	rotate_to_header(position, stack_a, stack_b, size);
}



int	chunks_alg(t_list **stack_a, t_list **stack_b)
{
	int	*array_1_D;
	int	size;
	int separator;
	int i;

	//Obtener el tamaño de la lista, crear un array de ints a partir de ella y ordenar el array de ints
	size = ft_lstsize(*stack_a);
	array_1_D = convert_to_int_array(*stack_a);
	if (!array_1_D)
		return (0);
	if (!merge_sort(array_1_D, size))
		return (0);
	//----------------------------Chunks_algorithm-------------------------------
	separator = size / 4;
	int temp = separator;
	while (size)
	{
		i = temp;
		while (i-- && size)
		{
			chunks_function(stack_a, stack_b, array_1_D, ft_lstsize(*stack_a), separator);
			size = ft_lstsize(*stack_a);
		}
		separator += temp;
		size = ft_lstsize(*stack_a);
	}
	//---------------------------------------------------------------------------
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