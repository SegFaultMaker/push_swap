/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:18:42 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/29 20:13:25 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	clean_buffer(char ***buffer)
{
	int	i;

	i = 0;
	while ((*buffer)[i])
	{
		free((*buffer)[i]);
		++i;
	}
	free(*buffer);
	*buffer = NULL;
	return ;
}

static int	num_counter(char *s)
{
	int	count;
	int	is_new;

	count = 0;
	is_new = 1;
	while (*s)
	{
		if (*s != ' ' && is_new)
		{
			is_new = 0;
			++count;
		}
		else if (*s == ' ' && !is_new)
			is_new = 1;
		++s;
	}
	return (count);
}

static int	check_args(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] != '\0')
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '-' && argv[i][j - 1] == ' ')
				j++;
			if (!ft_isdigit(argv[i][j]))
				quit_with_error();
			if (argv[i][j + 1] && argv[i][j] == '0' && argv[i][j - 1] == ' '
					&& argv[i][j + 1] != ' ')
				quit_with_error();
			j++;
		}
		i++;
	}
	return (1);
}

static int	*fill_res(char **argv, int argc, int size)
{
	int		i;
	int		j;
	int		k;
	int		*temp;
	char	**buffer;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return (NULL);
	i = 0;
	k = 1;
	while (k < argc)
	{
		buffer = ft_split(argv[k], ' ');
		if (!buffer)
			break ;
		j = 0;
		while (buffer[j] != NULL)
			temp[i++] = ft_atoi(buffer[j++]);
		clean_buffer(&buffer);
		++k;
	}
	return (temp);
}

int	get_arr(int **res, char **argv, int argc)
{
	int		i;
	int		size;

	check_args(argv, argc);
	size = 0;
	i = 1;
	while (i < argc)
	{
		size += num_counter(argv[i]);
		++i;
	}
	*res = fill_res(argv, argc, size);
	if (!*res)
		quit_with_error();
	return (size);
}
