/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:45:48 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/24 17:04:35 by nasargsy         ###   ########.fr       */
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

	ft_printf("==== Arr ====\n");
	for(int i = 0; i < size; i++)
		ft_printf("%d\n", arr[i]);

	a = fill_stack_a(arr, size);
	ft_printf("==== stack_a before Rotate ====\n");
	t_stack *temp;
	temp = a;
	while (a)
	{
		ft_printf("%d\n", a->num);
		a = a->next;
	}
	
	
	ft_printf("==== stack_a after Reverse Rotate ====\n");
	
	a = temp;
	reverse_rotate(&a);
	while (a)
	{
		ft_printf("%d\n", a->num);
		a = a->next;
	}
	a = temp;
		
//	heap_sort(arr, size);
//	b = fill_stack_b(&a, arr, size);
	free(arr);
	stack_clear(&a);
//	stack_clear(&b);
}
