/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:49:05 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/24 13:59:12 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*stack_new(int num)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->num = num;
	node->next = NULL;
	return (node);
}

void	stack_clear_a(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*next;

	if (!lst)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		temp->num = 0;
		free(temp);
		temp = next;
	}
	*lst = NULL;
}

t_stack	*fill_stack(int *arr, int size)
{
	int		i;
	t_stack	*stack;
	t_stack	*temp;

	stack = stack_new(arr[size - 1]);
	temp = stack;
	i = size - 2;
	while (i >= 0)
	{
		stack->next = stack_new(arr[i]);
		stack = stack->next;
		i--;
	}
	stack = temp;
	temp = NULL;
	return (stack);
}

t_stack	*fill_stack_b(it_stack *a, nt *arr, int size)
{
	
}
