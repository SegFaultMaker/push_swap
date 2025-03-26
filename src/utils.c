/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:24:09 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/26 16:35:34 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	quit_with_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	check_arr(int **arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if ((*arr)[i] == (*arr)[j])
			{
				free(*arr);
				quit_with_error();
			}
			j++;
		}
		i++;
	}
}
