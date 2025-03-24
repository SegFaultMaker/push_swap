/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:44:37 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/24 16:44:18 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <error.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

int		get_arr(int **res, char **argv, int argc);
void	heap_sort(int *arr, int n);
void	quit_with_error(void);
void	stack_clear(t_stack **lst);
void	stack_add_front(t_stack **lst, t_stack *new);
void	swap(t_stack **stack);
void	push(t_stack **first, t_stack **second);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
t_stack	*fill_stack_a(int *arr, int size);
t_stack	*fill_stack_b(t_stack *a, int *arr, int size);
#endif
