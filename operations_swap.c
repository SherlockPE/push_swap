/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:34:30 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/28 11:55:44 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_action(t_list	**stack)
{
	int size;
	t_list	*a;
	t_list	*b;
	t_list	*c;

//Caso de error
	size = ft_lstsize(*stack);
	if (size <= 1)
		return ;

//Agarrar valores
	a = *stack;
	b = a->next;
	c = b->next;

//Cambiar valores
	b->next = a;
	a->next = c;

//Reasignar cabecera
	*stack = b;
}

void	swap_a(t_list **stack_a)
{
	swap_action(stack_a);
	printf("sa\n");
}

void	swap_b(t_list **stack_b)
{
	swap_action(stack_b);
	printf("sb\n");
}

void	swap_ss(t_list **stack_a, t_list **stack_b)
{
	swap_action(stack_a);
	swap_action(stack_b);
	printf("ss\n");
}


// 1 --> *stack_a
// 2 --> b
// 3 --> c
// 4
// ---------------------------------
// ---------------------------------
