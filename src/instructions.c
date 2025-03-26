/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:18:42 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/26 17:05:41 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack **stack)
{
	int	temp;

	if ((*stack)->next == NULL)
		return ;
	temp = (*stack)->next->num;
	(*stack)->next->num = (*stack)->num;
	(*stack)->num = temp;
}

void	push(t_stack **first, t_stack **second)
{
	t_stack	*temp;

	if (*first == NULL)
		return ;
	temp = (*first)->next;
	(*first)->next = *second;
	*second = *first;
	*first = temp;
}

void	rotate(t_stack **stack)
{
	int		first_num;
	t_stack	*temp;

	first_num = (*stack)->num;
	temp = *stack;
	while ((*stack)->next != NULL)
	{
		(*stack)->num = (*stack)->next->num;
		*stack = (*stack)->next;
	}
	(*stack)->num = first_num;
	*stack = temp;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = *stack;
	*stack = temp->next;
	temp->next = NULL;
}
