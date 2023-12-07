/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:24:47 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/07 19:17:24 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_list(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;

	t_list	*a;
	t_list	*b;
	t_list	*z;
	// int size;

	while (!is_it_order_yet(*stack_a, 1))
	{
		a = *stack_a;
		b = a->next;
		z = ft_lstlast(*stack_a);

		printf("a: %d\nb: %d\nz: %d\n", *(int *)a->content, *(int *)b->content, *(int *)z->content);
		// printf("Operación: ");

		if (*(int *)a->content < *(int *)z->content && *(int *)a->content > *(int *)b->content )
			swap_a(stack_a);
		else if (((*(int *)b->content > *(int *)z->content)) && ((*(int *)z->content > *(int *)a->content)))
			reverse_rotate_a(stack_a);
		else if (*(int *)a->content > *(int *)b->content )
			rotate_a(stack_a);
		//print_listas(*stack_a, *stack_b);
	}
	// size = ft_lstsize(*stack_b);
	// while (size--)
	// 	push_a(stack_a, stack_b);
}
// void	sort_list_3_digits(t_list **stack, int order, void	swap(t_list **), void	rr(t_list **))
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
