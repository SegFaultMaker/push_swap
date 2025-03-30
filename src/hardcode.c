/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 hardcode.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: nasargsy <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/03/29 19:08:59 by nasargsy		   #+#	  #+#			  */
/*	 Updated: 2025/03/30 14:38:53 by nasargsy		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_three(t_stack **a)
{
	if ((*a)->num == 2)
	{
		rotate(a, 'a');
		if ((*a)->num == 0)
			return ;
	}
	if ((*a)->num == 1)
	{
		if ((*a)->next->num == 2)
			reverse_rotate(a, 'a');
		else
			swap(a, 'a');
	}
	else if ((*a)->num == 0)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
}

int	get_min_index(t_stack *stack)
{
	int		min_idx;
	int		num;
	t_stack	*temp;

	min_idx = 0;
	num = stack->num;
	temp = stack;
	while (stack)
	{
		if (stack->num < num)
			num = stack->num;
		stack = stack->next;
	}
	stack = temp;
	while (stack->num != num)
	{
		stack = stack->next;
		min_idx++;
	}
	stack = temp;
	return (min_idx);
}

static void	fill_until_three(t_stack **a, t_stack **b, int size)
{
	int	min_idx;

	while (size > 3)
	{
		min_idx = get_min_index(*a);
		if (min_idx <= size / 2)
		{
			while (min_idx--)
				rotate(a, 'a');
		}
		else
		{
			while (min_idx++ < size)
				reverse_rotate(a, 'a');
		}
		push(a, b, 'b');
		size--;
	}

}

void	hardcode_sort(t_stack **a, t_stack **b, int size)
{
	int	idx;

	if (size == 2)
		swap(a, 'a');
	else if (size == 3)
		sort_three(a);
	else if (size > 3)
	{
		fill_until_three(a, b, size);
		idx = get_max_index(*a);
		while (idx++ != 2)
			reverse_rotate(a, 'a');
		if (get_min_index(*a) == 1)
			swap(a, 'a');
		while (size > 3)
		{
			push(b, a, 'a');
			size--;
		}
	}
}
