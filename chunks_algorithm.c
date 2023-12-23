/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:37:16 by fabriciolop       #+#    #+#             */
/*   Updated: 2023/12/23 15:35:20 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunks_alg(t_list **stack_a, t_list **stack_b)
{
	int	*array;
	int	size;

	//Obtener el tamaño de la lista, crear un array de ints a partir de ella y ordenar el array de ints
	size = ft_lstsize(*stack_a);
	array = convert_to_int_array(*stack_a);
	if (!array)
		return (0);
	if (!merge_sort(array, size))
		return (0);
	//----------------------------Chunks_algorithm-------------------------------
	print_listas(*stack_a, *stack_b);
	move_elements_to_sb(stack_a, stack_b, size, array);
	print_listas(*stack_a, *stack_b);
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