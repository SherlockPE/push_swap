/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:24:47 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/29 21:57:37 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_list **stack_a, t_list **stack_b)
{
	// (void)stack_b;
	t_list	*a;
	t_list	*b;
	int		size;


	while (!is_it_order_yet(*stack_a, 1)) //Solo entra si la lista no está ordenada
	{
		while (!is_it_order_yet(*stack_a, 1)) //Solo entra si la lista no está ordenada
		{
			a = *stack_a;
			b = (*stack_a)->next;
			//print_listas(a, b);
			if (a->content > b->content) // a es menor que b?
			{
				push_b(stack_a, stack_b);
				print_listas(*stack_a, *stack_b);
			}
			else
			{
				reverse_rotate_a(stack_a);//probar con swap stack a
				print_listas(*stack_a, *stack_b);
			}
		}
		size = ft_lstsize(*stack_b);
		while (size--)
		{
			push_a(stack_a, stack_b);
			print_listas(*stack_a, *stack_b);
		}
	}
}

// //Comprobación de si mi lista ya está ordenada o no
// //Está ordenada la lista? si sí, no debo hacer nada
// if (is_it_order_yet(*stack_a, 1)) //Orden Ascendente
// {
// 	printf("La lista ESTÁ ordenada en Orden Ascendente\n");
// 	return ;
// }
// else if (is_it_order_yet(*stack_a, 2)) //Orden Descendente
// {
// 	printf("La lista ESTÁ ordenada en Orden Descendente\n");
// 	return ;
// }
// else
// {
// 	printf("La lista NO está ordenada\n");
//  	enter_parameter(stack_a, stack_b);
// }
