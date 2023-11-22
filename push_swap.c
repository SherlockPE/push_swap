/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:28:35 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/22 18:24:40 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	create_list(char **list_values, t_list **new_list)
{
	int i;
	int		content;
	t_list	*new_node;

	i = 1;
	new_list = 0;
	while (list_values[i])
	{
		content = ft_atoi(list_values[i]);
		new_node = ft_lstnew(&content);
		ft_lstadd_back(new_list, new_node);
		i++;
	}
}

void	print_lista(t_list *header)
{
	while (header)
	{
		printf("%d", (int)header->content);
		header = header->next;
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	t_list	*new_list;
	create_list(argv, &new_list);
	print_lista(new_list);
	return 0;
}
