/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:24:47 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/29 19:01:40 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_it_order_yet(t_list *stack)
{
	t_list	*tmp_next;

	while (stack)
	{
		tmp_next = stack->next;
		while (tmp_next)
		{
			if (*(int *)stack->content > *(int *)tmp_next->content)
				return (0);
			else if (*(int *)stack->content > *(int *)tmp_next->content)
				tmp_next = tmp_next->next;
			else
				tmp_next = tmp_next->next;
		}
		stack = stack->next;
	}
	return (1);
}

void	sort_list(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	
	//Está ordenada la lista? si sí, no debo hacer nada
	if (is_it_order_yet(*stack_a))
	{
		printf("La lista está ordenada\n");
		return ;
	}
	else
	{
		printf("La lista NO está ordenada\n");
	 	enter_parameter(stack_a, stack_b);
	}
}
