/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:37:16 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/12/20 18:10:31 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void    merge_action(int *original_array, int *copy_array, int  inicio, int size)
{
    int i;
    int middle;
    int m;

    middle = inicio + (size - inicio) / 2;
    m = middle;

    i = inicio;
    while (i < size)
    {
        if (inicio < middle && (m >= size || copy_array[inicio] <= copy_array[m]))
            original_array[i++] = copy_array[inicio++];
        else
            original_array[i++] = copy_array[m++];
    }
}

static void    merge_split(int *original_array, int *copy_array, int inicio, int size)
{
    int    middle;

    if (size - inicio <= 1)
        return ;
    middle = inicio + (size - inicio ) / 2;
    merge_split(copy_array, original_array, inicio, middle);
    merge_split(copy_array, original_array, middle, size);
    merge_action(original_array, copy_array, inicio, size);
}

int    merge_sort(int *original_array, int size)
{
    int    i;
    int    *copy_array;

	copy_array = ft_calloc(size, sizeof(int));
    if (!copy_array)
        return (0);

    i = -1;
    while (i++ < size - 1)
        copy_array[i] = original_array[i];

    merge_split(original_array, copy_array, 0, size);
    return (1);    
}

int	chunks_alg(t_list **stack_a, t_list **stack_b)
{
	// int	**array_2_D;
	int *array_1_D;
	int size;
	(void)stack_b;
	
	size = ft_lstsize(*stack_a);
	array_1_D = convert_to_int_array(*stack_a);
	if (!array_1_D)
		return (0);
	if (!merge_sort(array_1_D, size))
		return (0);
	
	//Imprimit array
	int i = 0;
	while (i < size)
	{
		printf("Number: %d\n", array_1_D[i]);
		i++;
	}

	// array_2_D = separate_in_chunks(array_1_D, size, separator);
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