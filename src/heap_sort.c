/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:23:53 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/22 15:29:16 by nasargsy         ###   ########.fr       */
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

void	heap_sort(int *arr, int n)
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
