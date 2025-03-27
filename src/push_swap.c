/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:45:48 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/27 20:35:53 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fill_stack_a(t_stack **stack, int *arr, int size)
{
	int		i;
	t_stack	*temp;

	*stack = stack_new(arr[0]);
	temp = *stack;
	i = 1;
	while (i < size)
	{
		(*stack)->next = stack_new(arr[i]);
		*stack = (*stack)->next;
		i++;
	}
	*stack = temp;
}

void	fill_stack_b(t_stack **b, t_stack **a, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (((*a)->num) <= i)
		{
			push(a, b);
			rotate(b);
			ft_printf("pb\nrb\n");
			i++;
		}
		else if (((*a)->num) <= i + (int)(ft_sqrt(size) * 1.5))
		{
			push(a, b);
			ft_printf("pb\n");
			i++;
		}
		else
		{
			rotate(a);
			ft_printf("ra\n");
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	int		*order;
	int		size;

	if (argc < 2)
		quit_with_error();
	a = NULL;
	b = NULL;
	size = get_arr(&arr, argv, argc);
	check_arr(&arr, size);
	get_order(&order, &arr, size);
	fill_stack_a(&a, order, size);
	fill_stack_b(&b, &a, size);
	free(arr);
	free(order);
	stack_clear(&a);
	stack_clear(&b);
}
