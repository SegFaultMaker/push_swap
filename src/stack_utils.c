/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:49:05 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/29 12:12:46 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*stack_new(int num)
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

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	get_max_index(t_stack *stack)
{
	int		max_idx;
	int		num;
	t_stack	*temp;

	max_idx = 0;
	num = stack->num;
	temp = stack;
	while (stack)
	{
		if (stack->num > num)
			num = stack->num;
		stack = stack->next;
	}
	stack = temp;
	while (stack->num != num)
	{
		stack = stack->next;
		max_idx++;
	}
	stack = temp;
	return (max_idx);
}
