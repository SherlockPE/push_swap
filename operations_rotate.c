/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:11:09 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/29 17:24:21 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_action(t_list **stack)
{
	t_list	*a;
	t_list	*b;
	t_list	*z;

	a = *stack;
	b = a->next;
	z = ft_lstlast(*stack);
	*stack = b;
	z->next = a;
	a->next = NULL;
}

void	rotate_a(t_list **stack_a)
{
	if (!error_content_size(stack_a))
		return ;
	rotate_action(stack_a);
	printf("ra\n");
}

void	rotate_b(t_list **stack_b)
{
	if (!error_content_size(stack_b))
		return ;
	rotate_action(stack_b);
	printf("rb\n");
}

void	rotate_rr(t_list **stack_a, t_list **stack_b)
{
	rotate_action(stack_a);
	rotate_action(stack_b);
	printf("rr\n");
}
