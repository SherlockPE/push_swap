/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:01:02 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/09 01:27:04 by fabriciolop      ###   ########.fr       */
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
}

void	add_values(t_list **new_list, char **array)
{
	int	i;
	int	j;
	int	*content;

	i = 0;
	j = 0;
	while (array[i])
	{
		content = malloc(sizeof(int));
		*content = ft_atoi(array[i]);
		ft_lstadd_back(new_list, ft_lstnew(content));
		i++;
	}
}

void	create_list(char **list_values, t_list **new_list)
{
	int		i;
	char	**box;

	i = 1;
	while (list_values[i])
	{
		box = ft_split(list_values[i], ' ');
		add_values(new_list, box);
		i++;
	}
}

// Function returns 0 if a not integer is found(ecept by '+' and '-' characters)
int	is_it_int(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '+' || array[i][j] == '-')
				j++;
			if (!ft_isdigit(array[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// Falta el 2.147.483.647 (número mayor a int)
// Function returns 0 if a error is founded, and 1 if everything is okay
int	check_errors(int argc, char **argv)
{
	int		i;
	char	**box;
	int		b_iterator;

	if (argc <= 1)
		return (0);
	i = 1;
	while (argv[i])
	{
		b_iterator = 0;
		box = ft_split(argv[i], ' ');
		if (!is_it_int(box))
			return (0);
		i++;
	}
	return (1);
}

int	error_content_size(t_list **stack)
{
	int	size;

	size = ft_lstsize(*stack);
	if (size <= 1)
		return (0);
	return (1);
}

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