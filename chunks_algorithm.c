/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:37:16 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/12/19 09:33:46 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	move_elements(t_list **stack_a, t_list **stack_b, int **array_2_D)
// {
		
// }

int	**free_array(int **result)
{
	//Falta el while
	free (result);
	return (0);
}

int	**separate_in_chunks(int *array, int size_initial, int separator)
{
	int    **result;
	int    num_blocks;
	int i;
	int j;
	int z;
	int impar;

	num_blocks = size_initial / separator;
	impar = 0;
	if (size_initial % 2 != 0)
	  num_blocks++;
	result = (int **)malloc(num_blocks * sizeof(int *));
	if (!result)
		return (0);
	i = 0;
	j = 0;
	while (j < num_blocks)
	{
		z = 0;
		if (j == (num_blocks - 1) && (size_initial % 2 == 0))
		  separator = size_initial - i;  
		result[j] = (int *)calloc(separator, sizeof(int));
		if (!result[j])
			return (free_array(result));
		while (z < separator)
			result[j][z++] = array[i++];
		j++;
	}
	return (result);
}

static void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

static void	order_array(int *array, int size) {
	int i;
	int swapped;

	while (1)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{ 
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				swapped = 1;
			}
			i++;
		}
		if (!swapped)
			break;
	}
}

int	chunks_alg(t_list **stack_a, t_list **stack_b)
{
	int *array_1_D;
	int	**array_2_D;
	int size;
	int separator;

	(void)stack_b;
	
	size = ft_lstsize(*stack_a);
	array_1_D = convert_to_int_array(*stack_a);
	if (!array_1_D)
		return (0);
	order_array(array_1_D, size);
	separator = size / 4;

//	array_2_D = separate_in_chunks(array_1_D, size, separator);

	
	//move_elements(stack_a, stack_b, array_2_D);
	return (1);
}

// int    main(void)
// {
// 	int size_initial = 10;
// 	int *initial;
// 	int separator = 2;

// 	initial = (int *)calloc(size_initial, sizeof(int));
// 	for (int i = 0; i < size_initial; ++i)
// 		initial[i] = i;
// 	// initial = {1, 2, 3, 4, 5, 6, 7, 8, 9}
// 	int **array_2d = separate_in_chunks(initial, size_initial, separator);
// 	// array_2d = { {0, 1}, {2, 3}, {4, 5}, {6, 7}, {8, 9}}

// 	return (0);
// }