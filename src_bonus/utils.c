/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:13:02 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/30 16:16:50 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	quit_with_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
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
	free(*arr);
	return (1);
}

void	clean_all(int **arr, t_stack **a, t_stack **b)
{
	free(*arr);
	if (*a)
		stack_clear(a);
	if (*b)
		stack_clear(b);
}
