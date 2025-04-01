/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:44:37 by nasargsy          #+#    #+#             */
/*   Updated: 2025/04/01 12:10:00 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <error.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

void		quit_with_error(void);
int			check_arr(int **arr, int size);
int			check_doubles(int *arr, int size);
void		check_args(char **argv, int argc);
void		clean_buffer(char ***buffer);
int			get_max_index(t_stack *stack);
long long	ft_atol(char *str);
int			generate_chunk(int size);
void		clean_all(int **arr, int **order, t_stack **a, t_stack **b);
int			get_arr(int **res, char **argv, int argc);
int			*get_order(int **res, int **arr, int size);
void		stack_clear(t_stack **lst);
t_stack		*stack_new(int num);
t_stack		*stack_last(t_stack *stack);
void		stack_add_front(t_stack **lst, t_stack *new);
void		swap(t_stack **stack, char c);
void		push(t_stack **first, t_stack **second, char c);
void		rotate(t_stack **stack, char c);
void		reverse_rotate(t_stack **stack, char c);
void		fill_stack_a(t_stack **a, int *arr, int size);
void		fill_stack_b(t_stack **b, t_stack **a, int size);
void		hardcode_sort(t_stack **a, t_stack **b, int size);
#endif
