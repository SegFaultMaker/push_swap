/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:25:03 by nasargsy          #+#    #+#             */
/*   Updated: 2025/04/01 11:04:28 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

void	quit_with_error(void);
int		check_arr(int **arr, int size);
int		check_doubles(int *arr, int size);
void	clean_all(int **arr, t_stack **a, t_stack **b);
int		get_arr(int **res, char **argv, int argc);
void	stack_clear(t_stack **lst);
t_stack	*stack_new(int num);
t_stack	*stack_last(t_stack *stack);
void	stack_add_front(t_stack **lst, t_stack *new);
void	swap(t_stack **stack);
void	push(t_stack **first, t_stack **second);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

#endif
