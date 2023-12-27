/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:11:40 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/27 16:32:40 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Function gets the position of the lowest element in the |array|
//not more than |size| elements
int	get_lower_number_position(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (size > j)
	{
		if (array[i] < array[j])
			j++;
		else
		{
			i = j;
			j = i + 1;
		}
	}
	return (i + 1);
}

//Function convert a list into a array of pointers
int	*convert_to_int_array(t_list *stack)
{
	int	i;
	int	*int_array;

	int_array = (int *)calloc(ft_lstsize(stack), sizeof(int *));
	if (!int_array)
		return (0);
	i = 0;
	while (stack)
	{
		int_array[i++] = *(int *)stack->content;
		stack = stack->next;
	}
	return (int_array);
}

//Function sort 3 numbers (needed to be in a bucle)
void	sort_5_cases(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)(*stack_a)->content;
	b = *(int *)((*stack_a)->next)->content;
	c = *(int *)(ft_lstlast(*stack_a)->content);
	if (a > b && a >= c && b <= c)
		rotate_a(stack_a);
	else if (a <= b && c < a && c < b)
		reverse_rotate_a(stack_a);
	else if ((a > b) || (a < b && c >= a))
		swap_a(stack_a);
}

//Retorna 0 si está desordenada y 1 si está ordenada
//Si order es 1 comprueba de forma ascendente 
//si es 2 o cualquier otro número, lo hace de forma descendente
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