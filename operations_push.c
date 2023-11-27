/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:18:48 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/27 13:45:50 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;

	//Caso de error
	if (!*stack_b)
		return ;

	// Agarrar valores
	a = *stack_b;
	b = a->next;

	// Nueva cabecera de stack_b
	*stack_b = b;

	// convertir la antigua cabecera de stack_b como la nueva cabecera de stack_a
	ft_lstadd_front(stack_a, a);
		// Dentro de la función se cambia el puntero de 'a' a la antigua cabecera de stack_b
	printf("pa\n");
	//push_b(stack_b, stack_a);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;

	//Caso de error
	if (!*stack_a)
		return ;

	// Agarrar valores
	a = *stack_a;
	b = a->next;

	// Nueva cabecera de stack_a
	*stack_a = b;

	// convertir la antigua cabecera de stack_a como la nueva cabecera de stack_b
	ft_lstadd_front(stack_b, a);
		// Dentro de la función se cambia el puntero de 'a' a la antigua cabecera de stack_b
	printf("pb\n");
}


// Stack_a | Stack_b
// 		1
// 		2
// 		3
// 		4
// 		5

// pb
// Stack_a | Stack_b
// 		2  | 	1
// 		3
// 		4
// 		5
