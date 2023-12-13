/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:11:40 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/13 15:35:04 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	chunks(stack_a, stack_b)
// {
	
// }

void	sort_5_cases(t_list **stack_a, int *count)
{
	int	a;
	int	b;
	int	c;

	// while (!is_it_order_yet(*stack_a, 1))
	// {
	a = *(int *)(*stack_a)->content;
	b = *(int *)((*stack_a)->next)->content;
	c = *(int *)(ft_lstlast(*stack_a)->content);
	if (a > b && a >= c && b <= c)
	{
		rotate_a(stack_a);
		(*count)++;
	}
	else if (a <= b && c < a && c < b)
	{
		reverse_rotate_a(stack_a);
		(*count)++;
	}
	else if ((a > b) || (a > b && b > c))
	{
		swap_a(stack_a);
		(*count)++;
	}
	else if (a < b && c >= a)
	{
		swap_a(stack_a);
		(*count)++;
	}
	// }
}

//Retorna 0 si está desordenada y 1 si está ordenada
//Si order es 1 comprueba de forma ascendente si es 2 o cualquier otro número, lo hace de forma descendente
int	is_it_order_yet(t_list *stack, int order)
{
	t_list	*tmp_next;

	while (stack)
	{
		tmp_next = stack->next;
		while (tmp_next)
		{
			if (order == 1)
			{
				if (*(int *)stack->content > *(int *)tmp_next->content)
					return (0);
				else
					tmp_next = tmp_next->next;
			}
			else
			{
				if (*(int *)stack->content < *(int *)tmp_next->content)
					return (0);
				else
					tmp_next = tmp_next->next;
			}
		}
		stack = stack->next;
	}
	return (1);
}

//1                           --> orden ascendente
//2 (o cualquier otro número) --> orden descendente

