/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:01:02 by flopez-r          #+#    #+#             */
/*   Updated: 2023/11/28 16:54:11 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_listas(t_list *header_a, t_list *header_b)
{
	printf("---------------------------------\n");
	printf("Stack a		|		Stack b\n");
	while (header_a || header_b)
	{
		if (header_a && header_b)
		{
			printf("%i		|		%i\n", *(int *)header_a->content, *(int *)header_b->content);
			header_a = header_a->next;
			header_b = header_b->next;
		}
		else if (header_a)
		{
			printf("%i		|			\n", *(int *)header_a->content);
			header_a = header_a->next;
		}
		else if (header_b)
		{
			printf("		|		%i\n", *(int *)header_b->content);
			header_b = header_b->next;
		}
	}
	printf("---------------------------------\n");
}

void	create_list(char **list_values, t_list **new_list)
{
	int	i;
	int	*content;

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

// Falta el 2.147.483.647 (número mayor a int)
int	check_errors(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc <= 1)
		return (0);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isalpha(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
