/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:45:48 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/23 17:26:36 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int		*arr;
	int		size;

	if (argc < 2)
		quit_with_error();
	size = get_arr(&arr, argv, argc);
	if (!arr)
	quit_with_error();
	
	for (int i = 0; i < size; i ++)
		ft_printf("%d\n", arr[i]);
	
	ft_printf("==========================\n");

	heap_sort(arr, size);
	for (int i = 0; i < size; i ++)
		ft_printf("%d\n", arr[i]);

	free(arr);
}
