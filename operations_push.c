/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:18:48 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/28 17:59:38 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;

	if (!*stack_b)
		return ;
	a = *stack_b;
	b = a->next;
	*stack_b = b;
	ft_lstadd_front(stack_a, a);
	printf("pa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;

	if (!*stack_a)
		return ;
	a = *stack_a;
	b = a->next;
	*stack_a = b;
	ft_lstadd_front(stack_b, a);
	printf("pb\n");
}
