/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:52:29 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/28 14:40:45 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	heapify(int arr[], int n, int i)
{
	int	largest;
	int	temp;
	int	l;
	int	r;

	largest = i;
	l = 2 * i + 1;
	r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr, n, largest);
	}
}

static void	heap_sort(int *arr, int n)
{
	int	i;
	int	temp;

	i = n / 2 - 1;
	while (i >= 0)
	{
		heapify(arr, n, i);
		i--;
	}
	i = n - 1;
	while (i > 0)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
		i--;
	}
}

static int	*fill_order(int *arr, int *sorted, int size)
{
	int	i;
	int	j;
	int	*order;

	order = malloc(size * sizeof(int));
	if (!order)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (arr[i] != sorted[j])
			j++;
		order[i] = j;
		i++;
	}
	return (order);
}

int	*get_order(int **res, int **arr, int size)
{
	int	i;
	int	*sorted;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sorted[i] = (*arr)[i];
		i++;
	}
	heap_sort(sorted, size);
	*res = fill_order(*arr, sorted, size);
	if (!*res)
	{
		free(sorted);
		free(*arr);
		quit_with_error();
	}
	free(sorted);
	return (*res);
}
