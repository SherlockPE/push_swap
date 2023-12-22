/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:37:16 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/12/22 16:39:43 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Function locates the first coincidence of |actual| in the |array| 
//(no more than |size| elements)
//Returns 1 if it founds sommething
//Returns 0 if it not found a coincidence
// int	is_it_belongs(int actual, int *array, int size)
// {
// 	if (actual <= size)
// 		return (1);
// 	return (0);
// }

static void	found_position(t_list **stack_a, int *array, int separator, int *position)
{
	int	actual;
	t_list *header;

	header = *stack_a;
	while (header)
	{
		actual = *(int *)(header)->content;
		printf("Valor actual: %d\n", actual);
		if (actual < array[separator])
			return ;
		(*position)++;
		header = (header)->next;
	}
}

static void	chunks_function(t_list **stack_a, t_list **stack_b, int *array_1_D, int size)
{
	int separator;
	int	position;
	int	iterations;
	separator = size / 4;

	position = 0;

	printf("Chunk actual: {");
	int i = 0;
	while (i < separator)
	{
		printf("%d", array_1_D[i]);
		i++;
	}
	printf("}\n");
	printf("Size: %d\n\n", size);

	//Encontrar un número que pertenezca al chunk actual
	found_position(stack_a, array_1_D, separator, &position);
	printf("Position: %d\n", position);

	//Rotar el numero encontrado hasta la cabecera
	if (position <= size / 2)
	{
		iterations = position;
		while (iterations--)
			rotate_a(stack_a);
	}
	else
	{
		iterations = size - position + 1;
		while (iterations--)
			reverse_rotate_a(stack_a);
	}

	//Function does pb
	push_b(stack_a, stack_b);
}

int	chunks_alg(t_list **stack_a, t_list **stack_b)
{
	int	*array_1_D;
	int	size;

	//Obtener el tamaño de la lista
	size = ft_lstsize(*stack_a);

	//Guardar la lista en un array de ints
	array_1_D = convert_to_int_array(*stack_a);
	if (!array_1_D)
		return (0);

	//Ordenar el array de ints
	if (!merge_sort(array_1_D, size))
		return (0);

	printf("Lista ordenada: ");
	int i = 0; 
	while (i < size)
	{
		printf("%d, ", array_1_D[i]);
		i++;
	}
	printf("\n");
	//Chunks_algorithm
	print_listas(*stack_a, *stack_b);

	chunks_function(stack_a, stack_b, array_1_D, size);

	print_listas(*stack_a, *stack_b);
	// Imprimit array
	// array_2_D = separate_in_chunks(array_1_D, size, separator);
	// move_elements(stack_a, stack_b, array_2_D);
	return (1);
}

// int    main(void)
// {
// 	int size_initial = 10;
// 	int *initial;
// 	int separator = 2;

// 	initial = (int *)calloc(size_initial, sizeof(int));
// 	// initial = {1, 2, 3, 4, 5, 6, 7, 8, 9}
// 	int **array_2d = separate_in_chunks(initial, size_initial, separator);
// 	// array_2d = { {0, 1}, {2, 3}, {4, 5}, {6, 7}, {8, 9}}

// 	return (0);
// }