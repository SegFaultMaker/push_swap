/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:45:48 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/25 13:57:25 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	int		size;

	if (argc < 2)
		quit_with_error();
	size = get_arr(&arr, argv, argc);
	if (!arr)
		quit_with_error();
	a = fill_stack_a(arr, size);
	heap_sort(arr, size);
	b = fill_stack_a(arr, size);
	free(arr);
	stack_clear(&a);
	stack_clear(&b);
}
