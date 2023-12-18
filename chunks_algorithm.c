/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:37:16 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/12/18 15:55:15 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_array(int **result)
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

int    **chunks_alg(t_list **stack_a, t_list **stack_b)
{
	int *array_1_D;
	int	**array_2_D;

	
	
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