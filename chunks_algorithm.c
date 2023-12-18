/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:37:16 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/12/18 09:38:06 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**chunks_alg(int *array, int size_initial, int separator)
{
	int	num_blocks;
	int	**result;

	// Num de bloques a separar
	num_blocks = size_initial / separator;
	// Crea un array de punteros
	result = (int **)malloc(num_blocks * sizeof(int *));
}

int	main(void)
{
	int size_initial = 10;
	int separator = 2;
	int *initial;

	initial = (int *)calloc(size_initial, sizeof(int));
	for (int i = 0; i < size_initial; ++i)
	{
		initial[i] = i;
	}
	int **array_2d = chunks_alg(initial, size_initial, separator);

	free(initial);
	return (0);
}