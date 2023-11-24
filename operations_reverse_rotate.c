/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:21:50 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/24 14:22:45 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list **stack_a)
{
	t_list	*z;
	int size;

	//Obtener valores
	z = ft_lstlast(*stack_a);
	size = ft_lstsize(*stack_a);

	//Cambiar valores 1
	//Añadir el ultimo elemento al principio
	ft_lstadd_front(stack_a, z);

	//Cambiar valores 2
	//Hacer que el penúltimo elemento apunte a NULL
	printf("len de la lista: %d\n", size);
	while (--size)
		z = z->next;
	z->next = NULL;
	printf("rra\n");
}

void	reverse_rotate_b(t_list **stack_b)
{
	t_list	*z;
	int size;

	//Obtener valores
	z = ft_lstlast(*stack_b);
	size = ft_lstsize(*stack_b);

	//Cambiar valores 1
	//Añadir el ultimo elemento al principio
	ft_lstadd_front(stack_b, z);

	//Cambiar valores 2
	//Hacer que el penúltimo elemento apunte a NULL
	printf("len de la lista: %d\n", size);
	while (--size)
		z = z->next;
	z->next = NULL;
	printf("rrb\n");
}

void	reverse_rotate_rr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	printf("rrr\n");
}


