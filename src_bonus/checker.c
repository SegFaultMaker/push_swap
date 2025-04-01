/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:37:37 by nasargsy          #+#    #+#             */
/*   Updated: 2025/04/01 13:50:10 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static void	fill_stack_a(t_stack **stack, int *arr, int size)
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

static int	check_stacks(t_stack *a, t_stack *b)
{
	if (b)
		return (0);
	while (a->next != NULL)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

static int	check_operations(t_stack **a, t_stack **b, char *op)
{
	if (ft_strncmp(op, "sa", 2) == 0)
		swap(a);
	else if (ft_strncmp(op, "sb", 2) == 0)
		swap(b);
	else if (ft_strncmp(op, "pa", 2) == 0)
		push(b, a);
	else if (ft_strncmp(op, "pb", 2) == 0)
		push(a, b);
	else if (ft_strncmp(op, "ra", 2) == 0)
		rotate(a);
	else if (ft_strncmp(op, "rb", 2) == 0)
		rotate(b);
	else if (ft_strncmp(op, "rra", 3) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(op, "rrb", 3) == 0)
		reverse_rotate(b);
	else
		return (0);
	return (1);
}

static int	do_operations(t_stack **a, t_stack **b)
{
	char	*op;

	op = get_next_line(0);
	while (op != NULL)
	{
		if (check_operations(a, b, op) == 0)
		{
			free (op);
			return (2);
		}
		free(op);
		op = get_next_line(0);
	}
	if (op)
		free(op);
	if (check_stacks(*a, *b) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	int		size;
	int		stat;

	if (argc < 2)
		quit_with_error();
	a = NULL;
	b = NULL;
	size = get_arr(&arr, argv, argc);
	check_arr(&arr, size);
	fill_stack_a(&a, arr, size);
	stat = do_operations(&a, &b);
	if (stat == 0)
		ft_printf("KO\n");
	else if (stat == 2)
		ft_putstr_fd("Error\n", 2);
	else
		ft_printf("OK\n");
	clean_all(&arr, &a, &b);
}
