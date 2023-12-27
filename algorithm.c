/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:24:47 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/27 16:34:19 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_list(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	contador;

	contador = 0;
	while (!is_it_order_yet(*stack_a, 1))
	{
		size = ft_lstsize(*stack_a);
		if (size <= 3)
			sort_5_cases(stack_a);
		else if (size <= 5)
		{
			if (!bubble_sort_algorithm(stack_a, stack_b))
				return (0);
		}
		else if (size <= 100)
		{
			if (!chunks_alg(stack_a, stack_b, 6))//<----- 6 es el más optimo
				return (0);
		}
		else
		{
			if (!chunks_alg(stack_a, stack_b, 20))
				return (0);
		}
	}
	return (1);
}
