/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:13:02 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/29 13:50:08 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	quit_with_error(void)
{
	ft_printf("Error\n");
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

int	generate_chunk(int size)
{
	int	chunk;

	chunk = 1;
	if (size < 50)
		chunk = 3 + (size - 6) / 7;
	else if (size >= 50 && size < 100)
		chunk = 10 + (size - 50) / 8;
	else if (size >= 100 && size < 350)
		chunk = 18 + (size - 100) / 9;
	else if (size >= 350 && size <= 500)
		chunk = 27 + (size - 350) / 15;
	else if (size > 500)
		chunk = 37 + (size - 500) / 20;
	return (chunk);
}

void	clean_all(int **arr, int **order, t_stack **a, t_stack **b)
{
	free(arr);
	free(order);
	if (*a)
		stack_clear(a);
	if (*b)
		stack_clear(b);
}
