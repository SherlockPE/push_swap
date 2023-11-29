/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:24:47 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/29 20:47:13 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	
	//Está ordenada la lista? si sí, no debo hacer nada
	if (is_it_order_yet(*stack_a, 1)) //Orden Ascendente
	{
		printf("La lista ESTÁ ordenada en Orden Ascendente\n");
		return ;
	}
	else if (is_it_order_yet(*stack_a, 2)) //Orden Descendente
	{
		printf("La lista ESTÁ ordenada en Orden Descendente\n");
		return ;
	}
	else
	{
		printf("La lista NO está ordenada\n");
	 	enter_parameter(stack_a, stack_b);
	}
}
