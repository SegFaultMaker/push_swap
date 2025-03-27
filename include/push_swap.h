/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:44:37 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/27 20:36:49 by nasargsy         ###   ########.fr       */
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

void	quit_with_error(void);
void	check_arr(int **arr, int size);
int		ft_sqrt(int nb);
int		get_arr(int **res, char **argv, int argc);
int		*get_order(int **res, int **arr, int size);
void	stack_clear(t_stack **lst);
t_stack	*stack_new(int num);
t_stack	*stack_last(t_stack *stack);
void	stack_add_front(t_stack **lst, t_stack *new);
void	swap(t_stack **stack);
void	push(t_stack **first, t_stack **second);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	fill_stack_a(t_stack **a, int *arr, int size);
void	fill_stack_b(t_stack **b, t_stack **a, int size);
#endif
