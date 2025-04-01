/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:49:48 by nasargsy          #+#    #+#             */
/*   Updated: 2025/04/01 13:49:50 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	check_for_digits(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (!ft_isdigit(argv[i][j]))
				quit_with_error();
			j++;
		}
		i++;
	}
}

static void	check_for_int(char **argv, int argc)
{
	int		i;
	int		j;
	char	**temp;

	i = 1;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
		{
			ft_putstr_fd("ft_split: ", 2);
			quit_with_error();
		}
		j = -1;
		while (temp[++j])
		{
			if (ft_atol(temp[j]) < INT_MIN || ft_atol(temp[j]) > INT_MAX)
			{
				clean_buffer(&temp);
				quit_with_error();
			}
		}
		clean_buffer(&temp);
		i++;
	}
}

void	check_args(char **argv, int argc)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			quit_with_error();
		i++;
	}
	check_for_digits(argv, argc);
	check_for_int(argv, argc);
}
