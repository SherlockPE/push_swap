/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:11:09 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/28 11:48:06 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_action(t_list	**stack)
{
	t_list	*a;
	t_list	*b;
	t_list	*z;

//Agarrar valores
	a = *stack;
	b = a->next;
	z = ft_lstlast(*stack);

//Cambiar valores

	//Cambiar la cabecera al segundo valor
	*stack = b;

	//El último elemento apuntará al que ANTES era el primero
	z->next = a;
	
	//El que será el último elemento apunta a NULL
	a->next = NULL;
}

void	rotate_a(t_list **stack_a)
{
	rotate_a(stack_a);
	printf("ra\n");
}

void	rotate_b(t_list **stack_b)
{
	rotate_action(stack_b);
	printf("rb\n");
}

void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	rotate_action(stack_a);
	rotate_action(stack_b);
	printf("rr\n");
}