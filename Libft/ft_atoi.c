/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:23:42 by flopez-r          #+#    #+#             */
/*   Updated: 2023/12/12 16:26:33 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(const char *str)
{
	int	symbol;
	long	number;

	number = 0;
	symbol = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			symbol = -symbol;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * symbol);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char number[] = "				-1234ab567";

// 	int a = ft_atoi(number);
// 	printf("%d", a);
// }