/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:52:29 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/23 12:02:15 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	quit_with_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

t_list	*fill_stack(int *arr, int size)
{
	int		i;
	t_list	*stack;
	
	i = 0;
	stack = ft_lstnew((void *)arr[i]);
	if (!stack)
		return (NULL);
	i = 1;
	while (i < size)
	{
		stack = ft_lstnew((void *)arr[i]);
		if (!stack)
			return (NULL);
		i++;
	}
}
