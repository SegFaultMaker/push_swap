/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:21:04 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/21 12:47:24 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*get_arr(char **argv, int argc)
{
	int		i;
	int		*res;
	char	**buffer;

	i = 1;
	while (i < argc)
	{
		buffer = ft_split(argv[i], ' ');
		if (check_arg(buffer) == -1)
		{
			clean_buffer(&buffer);
			return (0);
		}
		res = fill_res(buffer, &res);
		clean_buffer(&buffer);
		i++;
	}
	res[i]
}
