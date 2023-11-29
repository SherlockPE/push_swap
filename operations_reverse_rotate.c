/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:21:50 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/29 17:14:11 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_action(t_list **stack)
{
	t_list	*z;
	int		size;

	z = ft_lstlast(*stack);
	size = ft_lstsize(*stack);
	ft_lstadd_front(stack, z);
	while (--size)
		z = z->next;
	z->next = NULL;
}

void	reverse_rotate_a(t_list **stack_a)
{
	reverse_action(stack_a);
	printf("rra\n");
}

void	reverse_rotate_b(t_list **stack_b)
{
	reverse_action(stack_b);
	printf("rrb\n");
}

void	reverse_rotate_rr(t_list **stack_a, t_list **stack_b)
{
	reverse_action(stack_a);
	reverse_action(stack_b);
	printf("rrr\n");
}
