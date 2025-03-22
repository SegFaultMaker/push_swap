/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:45:48 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/22 15:34:52 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	quit_with_error(void)
{
	printf("Error\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	int		*arr;
	int		size;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		quit_with_error();
	size = get_arr(&arr, argv, argc);
	if (!arr)
		quit_with_error();
	heap_sort(arr, size);
	free(arr);
}
