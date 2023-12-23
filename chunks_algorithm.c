/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:37:16 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/12/23 14:02:45 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(int	*array_1_D, int count)
{
	printf("Array ordenado: \n");
	for (int i = 0; i < count; i++)
	{
		printf("%d\n", array_1_D[i]);
	}
}

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
	print_listas(*stack_a, *stack_b);
}

static void	found_position(t_list *stack_a, int *array, int separator, int *position)
{
	int	actual;

	printf("Valor de separator (chunk): %d\n", separator);
	while (stack_a)
	{
		actual = *(int *)(stack_a)->content;
		printf("Valor actual: %d\n", actual);
		printf("Position: %d\n\n", *position);
		if (actual <= array[separator])
			return ;
		(*position)++;
		stack_a = (stack_a)->next;
	}
}

static void	chunks_function(t_list **stack_a, t_list **stack_b, int *array_1_D, int size, int separator)
{
	int	position;
	position = 0;


	//Encontrar un número que pertenezca al chunk actual
	printf("\nIniciando busqueda: \n");
	found_position(*stack_a, array_1_D, separator, &position);
	printf("\nPosition: %d\n", position);

	//Rotar el numero encontrado hasta la cabecera y moverlo al stack B
	printf("Rotando el número y moviendolo al stack_b\n");
	rotate_to_header(position, stack_a, stack_b, size);

}



int	chunks_alg(t_list **stack_a, t_list **stack_b)
{
	int	*array_1_D;
	int	size;
	int separator;

	//Obtener el tamaño de la lista, crear un array de ints a partir de la lista y ordenar el array de ints
	size = ft_lstsize(*stack_a);
	array_1_D = convert_to_int_array(*stack_a);
	if (!array_1_D)
		return (0);
	if (!merge_sort(array_1_D, size))
		return (0);

	//print array of ints
	print_array(array_1_D, size);

	//Chunks_algorithm
	print_listas(*stack_a, *stack_b);
	//---------------------------------------------------------------------------
	// while (size)
	// {
	separator = size / 4;
	int i;
	while (size)
	{
		size = ft_lstsize(*stack_a);
		i = separator + 1;
		while (i--)
			chunks_function(stack_a, stack_b, array_1_D, ft_lstsize(*stack_a), separator);
		separator += separator;
	}
	
	chunks_function(stack_a, stack_b, array_1_D, size, separator);
	// }
	//---------------------------------------------------------------------------	
	print_listas(*stack_a, *stack_b);
	return (1);
}










	// printf("Lista ordenada: ");
	// int i = 0; 
	// while (i < size)
	// {
	// 	printf("%d, ", array_1_D[i]);
	// 	i++;
	// }

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