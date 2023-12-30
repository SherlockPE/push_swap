/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:34:30 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/29 17:21:57 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_action(t_list **stack)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = *stack;
	b = a->next;
	c = b->next;
	b->next = a;
	a->next = c;
	*stack = b;
}

void	swap_a(t_list **stack_a)
{
	if (!error_content_size(stack_a))
		return ;
	swap_action(stack_a);
	printf("sa\n");
}

void	swap_b(t_list **stack_b)
{
	if (!error_content_size(stack_b))
		return ;
	swap_action(stack_b);
	printf("sb\n");
}

void	swap_ss(t_list **stack_a, t_list **stack_b)
{
	swap_action(stack_a);
	swap_action(stack_b);
	printf("ss\n");
}
