/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasargsy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:44:37 by nasargsy          #+#    #+#             */
/*   Updated: 2025/03/23 17:17:12 by nasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <error.h>
# include "../libft/libft.h"

int		get_arr(int **res, char **argv, int argc);
void	heap_sort(int *arr, int n);
void	quit_with_error(void);
#endif
