/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:13:42 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/30 17:41:02 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_action(int *original_array, int *copy_array, int inicio,
		int size)
{
	int	i;
	int	middle;
	int	m;

	middle = inicio + (size - inicio) / 2;
	m = middle;
	i = inicio;
	while (i < size)
	{
		if (inicio < middle && (m >= size
				|| copy_array[inicio] <= copy_array[m]))
			original_array[i++] = copy_array[inicio++];
		else
			original_array[i++] = copy_array[m++];
	}
}

static void	merge_split(int *original_array, int *copy_array, int inicio,
		int size)
{
	int	middle;

	if (size - inicio <= 1)
		return ;
	middle = inicio + (size - inicio) / 2;
	merge_split(copy_array, original_array, inicio, middle);
	merge_split(copy_array, original_array, middle, size);
	merge_action(original_array, copy_array, inicio, size);
}

int	merge_sort(int *original_array, int size)
{
	int	i;
	int	*copy_array;

	copy_array = ft_calloc(size, sizeof(int));
	if (!copy_array)
		return (0);
	i = -1;
	while (i++ < size - 1)
		copy_array[i] = original_array[i];
	merge_split(original_array, copy_array, 0, size);
	free(copy_array);
	return (1);
}
