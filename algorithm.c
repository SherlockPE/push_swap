/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:24:47 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/04 16:33:59 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list_3_digits(t_list **stack)
{
	t_list	*a;
	t_list	*b;


	while (!is_it_order_yet(*stack, 1))
	{
		a = *stack;
		b = a->next;
		printf("Contenido de a: %d\n", *(int *)a->content);
		printf("Contenido de b: %d\n", *(int *)b->content);
		if (a->content > b->content) //si a es mayor que b
			swap_a(stack);
		else // si a es menor que b
			reverse_rotate_a(stack);
	}
}

void	sort_list(t_list **stack_a, t_list **stack_b)
{
	// int	size;

	(void)stack_b;
	// size = ft_lstsize(*stack_a);
	
	sort_list_3_digits(stack_a);
	// while (!is_it_order_yet(*stack_a, 1))
	// {

	// 	if (size <= 3)
	// 		sort_list_3_digits(stack_a, a, b);
	// 	else
	// 		break ;
	// }
}
























// while (!is_it_order_yet(*stack_a, 1))
// Solo entra si la lista no está ordenada
// {
// 	while (!is_it_order_yet(*stack_a, 1))
// Solo entra si la lista no está ordenada
// 	{
// 		a = *stack_a;
// 		b = a->next;
// 		//print_listas(a, b);
// 		if (a->content >= b->content) // a es menor que b?
// 			push_b(stack_a, stack_b);
// 		else
// 		{
// 			//rotate_a(stack_a);
// 			reverse_rotate_a(stack_a);//probar con swap stack a
// 		}
// 		print_listas(*stack_a, *stack_b);
// 	}
// 	size = ft_lstsize(*stack_b);
// 	while (size--)
// 	{
// 		push_a(stack_a, stack_b);
// 		print_listas(*stack_a, *stack_b);
// 	}
// }

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
