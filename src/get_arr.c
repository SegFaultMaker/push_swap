/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:18:42 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/21 17:55:20 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>
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
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

static int	*fill_res(char **argv, int argc, int size)
{
	int		i;
	int		j;
	int		*temp;
	char	**buffer;

	temp = malloc(sizeof(int) * size);
	i = 0;
	while (argc > 1)
	{
		buffer = ft_split(argv[argc - 1], ' ');
		j = 0;
		while (buffer[j] != NULL)
		{
			
			temp[i] = ft_atoi(buffer[j]);
			printf("temp[%d]: %d\n", i, temp[i]);
			i++;
			j++;
		}
		clean_buffer(&buffer);
		--argc;
	}
	return (temp);
}

int	*get_arr(char **argv, int argc)
{
	int		i;
	int		*res;
	int		size;

	if (check_args(argv, argc) == -1)
		return (0);
	size = 0;
	i = 1;
	while (i < argc)
	{
		size += num_counter(argv[i]);
		++i;
	}
	res = fill_res(argv, argc, size);
	return (res);
}

int main(int argc, char **argv)
{
	int	*res;
	int	size = 0;
	printf("===== Checking check_args =====\n");
	for(int	i = 1; i < argc; i++)
		printf("%s\n", argv[i]);
	printf("-------------------------------\n");
	if (check_args(argv, argc) == -1)
		printf("false\n\n");
	else
		printf("true\n\n");
	
	
	printf("===== Checking num_counter =====\n");
	for (int i = 1; i < argc; i++)
	{
		printf("%s: %d\n", argv[i], num_counter(argv[i]));
		size += num_counter(argv[i]);
	}
	printf("--------------------------------\n");
	printf("In Total: %d\n\n", size);

	printf("===== Checking fill_res  =====\n");
	res = fill_res(argv, argc, size);
	printf("------------------------------------\n");
	printf("SUCCESS\n\n");
}
