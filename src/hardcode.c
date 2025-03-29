/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:08:59 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/29 19:39:54 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	sort_three(t_stack **a)
{
	if ((*a)->num == 2)
	{
		rotate(a);
		ft_printf("ra\n");
		if ((*a)->num == 1)
		{
			swap(a);
			ft_printf("sa\n");
		}
	}
	else if ((*a)->num == 1)
	{
		swap(a);
		ft_printf("sa\n");
		if ((*a)->num == 2)
		{
			rotate(a);
			ft_printf("ra\n");
		}
	}
	else if ((*a)-> == 0)
	{
		swap(a);
		rotate(a);
		ft_printf("sa\nra\n");
	}
	
}

void	hardcode_sort(t_stack **a, int size)
{
	if (size == 2)
	{
		swap(a);
		ft_printf("sa\n");
	}
	else if (size == 3)
		sort_three(a);
}

