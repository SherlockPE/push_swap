/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:24:47 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/14 19:24:40 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_list(t_list **stack_a, t_list **stack_b)
{
	if(!bubble_sort_algorithm(stack_a, stack_b))
		return(0);
	// int	size;
	// int	size_b;
	// int	contador;

	// contador = 0;
	// while (!is_it_order_yet(*stack_a, 1))
	// {
	// 	size = ft_lstsize(*stack_a);
	// 	if (size <= 3)
	// 	{
	// 		sort_5_cases(stack_a, &contador);
	// 	}
	// 	else if (size >= 4 && size <= 5)
	// 	{
	// 		bubble_sort_algorithm(stack_a, stack_b);
	// 	}
	// 	// size_b = ft_lstsize(*stack_b);
	// 	// while (size_b && is_it_order_yet(*stack_a, 1))
	// 	// {
	// 	// 	push_a(stack_a, stack_b);
	// 	// 	contador++;
	// 	// 	size_b = ft_lstsize(*stack_b);
	// 	// }
	// }
	// printf("\n\nCantidad de operaciones: %d\n", contador);
	return (1);
}

// void	sort_list(t_list **stack_a, t_list **stack_b)
// {
// 	int	size;
// 	int	size_b;
// 	int	contador;

// 	contador = 0;

// 	while (!is_it_order_yet(*stack_a, 1))
// 	{
// 		size = ft_lstsize(*stack_a);
// 		if (size <= 3)
// 		{
// 			sort_5_cases(stack_a, &contador);
// 		}
// 		else if (size >= 4 && size <= 5)
// 		{
// 			sort_5_cases(stack_a, &contador);
// 			while (size - 3 && !is_it_order_yet(*stack_a, 1))
// 			{
// 				push_b(stack_a, stack_b);
// 				contador++;
// 				size--;
// 			}
// 		}
// 		size_b = ft_lstsize(*stack_b);
// 		while (size_b && is_it_order_yet(*stack_a, 1))
// 		{
// 			push_a(stack_a, stack_b);
// 			contador++;
// 			size_b = ft_lstsize(*stack_b);
// 		}
// 	}
// 	printf("\n\nCantidad de operaciones: %d\n\n", contador);
// }

// printf("a: %d\nb: %d\nc: %d\n\n\n", a, b, c);
// void	sort_list_3_digits(t_list **stack, int order, void	swap(t_list **),
// void	rr(t_list **))
// {
// 	t_list	*a;
// 	t_list	*b;

// 	while (!is_it_order_yet(*stack, order))
// 	{
// 		a = *stack;
// 		b = a->next;
// 		if (order == 1)
// 		{
// 			if (*(int *)a->content > *(int *)b->content) //Orden ascendente
// 				swap(stack);
// 			else
// 				rr(stack);
// 		}
// 		else
// 		{
// 			if (*(int *)a->content < *(int *)b->content) //Orden descendente
// 				swap(stack);
// 			else
// 				rr(stack);
// 		}
// 	}
// }
// void	sort_list(t_list **stack_a, t_list **stack_b)
// {
// 	(void)stack_b;
// 	t_list	*a;
// 	t_list	*b;
// 	int	size_a;
// 	int	size_b;

// 	size_a = ft_lstsize(*stack_a);
// 	size_b = ft_lstsize(*stack_b);

// 	while ((!is_it_order_yet(*stack_a, 1) || !is_it_order_yet(*stack_b, 2)) && )
// 	{
// 		a = *stack_a;
// 		b = a->next;
// 		if (*(int *)a->content > *(int *)b->content)
// 			push_b(stack_a, stack_b);
// 		else
// 			reverse_rotate_a(stack_a);
// 		if (size_a <= 3 && !is_it_order_yet(*stack_a, 1))
// 			sort_list_3_digits(stack_a, 1, swap_a, reverse_rotate_a);
// 		else if (size_b <= 3 && !is_it_order_yet(*stack_b, 2))
// 			sort_list_3_digits(stack_b, 2, swap_b, reverse_rotate_b);
// 		print_listas(*stack_a, *stack_b);
// 	}

// }

// printf("Contenido de a: %d\n", *(int *)a->content);
// printf("Contenido de b: %d\n\n", *(int *)b->content);

// while (!is_it_order_yet(*stack_a, 1))
// Solo entra si la lista no está ordenada
// {
// 	while (!is_it_order_yet(*stack_a, 1))
// Solo entra si la lista no está ordenada
// 	{
// 		a = *stack_a;
// 		b = a->next;
// 		//print_listas(a, b);
// 		if (a->content >= b->content) // a es menor que b?
// 			push_b(stack_a, stack_b);
// 		else
// 		{
// 			//rotate_a(stack_a);
// 			reverse_rotate_a(stack_a);//probar con swap stack a
// 		}
// 		print_listas(*stack_a, *stack_b);
// 	}
// 	size = ft_lstsize(*stack_b);
// 	while (size--)
// 	{
// 		push_a(stack_a, stack_b);
// 		print_listas(*stack_a, *stack_b);
// 	}
// }

// //Comprobación de si mi lista ya está ordenada o no
// //Está ordenada la lista? si sí, no debo hacer nada
// if (is_it_order_yet(*stack_a, 1)) //Orden Ascendente
// {
// 	printf("La lista ESTÁ ordenada en Orden Ascendente\n");
// 	return ;
// }
// else if (is_it_order_yet(*stack_a, 2)) //Orden Descendente
// {
// 	printf("La lista ESTÁ ordenada en Orden Descendente\n");
// 	return ;
// }
// else
// {
// 	printf("La lista NO está ordenada\n");
//  	enter_parameter(stack_a, stack_b);
// }
