/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:11:40 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/07 16:20:24 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Retorna 0 si está desordenada y 1 si está ordenada
//Si order es 1 comprueba de forma ascendente si es 2 o cualquier otro número, lo hace de forma descendente
int	is_it_order_yet(t_list *stack, int order)
{
	t_list	*tmp_next;

	while (stack)
	{
		tmp_next = stack->next;
		while (tmp_next)
		{
			if (order == 1)
			{
				if (*(int *)stack->content > *(int *)tmp_next->content)
					return (0);
				else
					tmp_next = tmp_next->next;
			}
			else
			{
				if (*(int *)stack->content < *(int *)tmp_next->content)
					return (0);
				else
					tmp_next = tmp_next->next;
			}
		}
		stack = stack->next;
	}
	return (1);
}

//1                           --> orden ascendente
//2 (o cualquier otro número) --> orden descendente