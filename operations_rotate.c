/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:11:09 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/24 13:03:01 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	t_list	*a;
	t_list	*b;
	t_list	*z;

//Agarrar valores
	a = *stack_a;
	b = a->next;
	z = ft_lstlast(*stack_a);

//Cambiar valores

	//Cambiar la cabecera al segundo valor
	*stack_a = b;

	//El último elemento apuntará al que ANTES era el primero
	z->next = a;
	
	//El que será el último elemento apunta a NULL
	a->next = NULL;

	printf("ra\n");
}

void	rotate_b(t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	t_list	*z;

//Agarrar valores
	a = *stack_b;
	b = a->next;
	z = ft_lstlast(*stack_b);

//Cambiar valores

	//Cambiar la cabecera al segundo valor
	*stack_b = b;

	//El último elemento apuntará al que ANTES era el primero
	z->next = a;
	
	//El que será el último elemento apunta a NULL
	a->next = NULL;

	printf("rb\n");
}

void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);

	printf("rb\n");
}