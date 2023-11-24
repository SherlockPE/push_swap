/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:34:30 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/24 11:06:31 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	swap_a(t_list **stack_a)
{
	int size;
	t_list	*a;
	t_list	*b;
	t_list	*c;

//Caso de error
	size = ft_lstsize(*stack_a);
	if (size <= 1)
		return ;

//Agarrar valores
	a = *stack_a;
	b = a->next;
	c = b->next;

//Cambiar valores
	b->next = a;
	a->next = c;

//Reasignar cabecera
	*stack_a = b;
	printf("sa\n");
}

void	swap_b(t_list **stack_b)
{
	int size;
	t_list	*a;
	t_list	*b;
	t_list	*c;

//Caso de error
	size = ft_lstsize(*stack_b);
	if (size <= 1)
		return ;

//Agarrar valores
	a = *stack_b;
	b = a->next;
	c = b->next;

//Cambiar valores
	b->next = a;
	a->next = c;

//Reasignar cabecera
	*stack_b = b;
	printf("sb\n");
}

void	swap_ss(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}


// 1 --> *stack_a
// 2 --> b
// 3 --> c
// 4
// ---------------------------------
// ---------------------------------
