/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:49:05 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/25 14:00:14 by nasargsy         ###   ########.fr       */
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

void	stack_add_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	stack_clear(t_stack **lst)
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

t_stack	*fill_stack_a(int *arr, int size)
{
	int		i;
	t_stack	*stack;
	t_stack	*temp;

	stack = stack_new(arr[0]);
	temp = stack;
	i = 1;
	while (i < size)
	{
		stack->next = stack_new(arr[i]);
		stack = stack->next;
		i++;
	}
	stack = temp;
	temp = NULL;
	return (stack);
}

t_stack	*fill_stack_b(t_stack *a, int *arr, int size)
{
	
}
