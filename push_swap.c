/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:28:35 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/23 20:29:49 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_list(char **list_values, t_list **new_list)
{
	int i;
	int		*content;

	i = 1;
	content = (int *)malloc(sizeof(int));
	*content = ft_atoi(list_values[i]);
	*new_list = ft_lstnew(content);
	while (list_values[++i])
	{
		content = (int *)malloc(sizeof(int));
		*content = ft_atoi(list_values[i]);
		ft_lstadd_back(new_list, ft_lstnew(content));
	}
}

void	print_lista(t_list *header)
{
	// printf("---------------------------------\n");
	while (header)
	{
		printf("%i\n", *(int *)header->content);
		header = header->next;
	}
	printf("---------------------------------\n");
	printf("---------------------------------\n");
}

int main(int argc, char **argv)
{
	(void)argc;
	t_list	*new_list;
	create_list(argv, &new_list);
	print_lista(new_list);
	
	swap_a(&new_list);
	print_lista(new_list);
	
	swap_b(&new_list);
	print_lista(new_list);
	return 0;
}
