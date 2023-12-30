/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:01:02 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/30 16:10:23 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_perror(char *message)
{
	ft_putstr_fd(message, 2);
	return (0);
}

int	clear_lista(t_list **lista)
{
	ft_lstclear(lista, free);
	ft_perror("Error\n");
	return (0);
}

// This function is a dependency of the function "create_list"
static int	add_values(t_list **new_list, char **array)
{
	int		i;
	int		j;
	long	*content;

	i = 0;
	j = 0;
	while (array[i])
	{
		content = malloc(sizeof(long));
		if (!content)
			return (clear_lista(new_list));
		*content = ft_atoi(array[i]);
		if (*content > INT_MAX || *content < INT_MIN)
			return (clear_lista(new_list));
		ft_lstadd_back(new_list, ft_lstnew(content));
		i++;
	}
	return (1);
}

int	create_list(char **list_values, t_list **new_list)
{
	int		i;
	char	**box;

	i = 1;
	while (list_values[i])
	{
		box = ft_split(list_values[i], ' ');
		if (!add_values(new_list, box))
			return (0);
		i++;
	}
	return (repeat_numbers(*new_list));
}

int	error_content_size(t_list **stack)
{
	int	size;

	size = ft_lstsize(*stack);
	if (size <= 1)
		return (0);
	return (1);
}

/* void	print_listas(t_list *header_a, t_list *header_b)
{
	printf("---------------------------------\n");
	printf("Stack a		|		Stack b\n");
	while (header_a || header_b)
	{
		if (header_a && header_b)
		{
			printf("%i		|		%i\n", *(int *)header_a->content,
								*(int *)header_b->content);
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
} */

// Falta el 2.147.483.647 (número mayor a int)

// if the list size is <= 1 it returns 0 else return 1

// j = 0;
// while (argv[i][j])
// {
// 	if (argv[i][j] == '-' || argv[i][j] == '+')
// 		j++;
// 	if (!ft_isdigit(argv[i][j]))
// 		return (0);
// 	j++;
// }
// if (j > 11)
// 	return (0);
// i++;