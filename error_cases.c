/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:08:39 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/13 16:41:50 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	repeat_numbers(t_list	*new_list)
{
	int *actual_content;
	t_list	*temp;
	
	temp = new_list->next;
	while (new_list)
	{
		actual_content = (int *)new_list->content;
		while (temp)
		{
			if (actual_content == (int *)temp->content)
			{
				printf("Error\n");
				return (0);
			}
			temp = temp->next;
		}
		new_list = new_list->next;
	}
	return (1);
}


// Function returns 0 if a not integer is found(ecept by '+' and '-' characters)
static int	is_it_int(char **array)
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

static void	free_split(char **array)
{
	int	index;

	index = 0;
	while (array[index++])
		free(array[index]);
	free(array);
}

// Function returns 0 if a error is founded and 1 if everything is okay
int	check_errors(int argc, char **argv, t_list **stack_a)
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
			return (free_split(box), 0);
		i++;
		free_split(box);
	}
	ft_lstclear(stack_a, free);
	return (1);
}
