/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:13:02 by nasargsy          #+#    #+#             */
/*   Updated: 2025/04/01 13:51:38 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

long long	ft_atol(char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	check_doubles(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_arr(int **arr, int size)
{
	int	i;

	i = 0;
	if (check_doubles(*arr, size))
	{
		free(*arr);
		quit_with_error();
	}
	while (i < size - 1)
	{
		if ((*arr)[i] > (*arr)[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	quit_with_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	clean_all(int **arr, t_stack **a, t_stack **b)
{
	if (*arr)
		free(*arr);
	if (*a)
		stack_clear(a);
	if (*b)
		stack_clear(b);
}
