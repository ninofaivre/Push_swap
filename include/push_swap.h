/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:27:00 by nino              #+#    #+#             */
/*   Updated: 2021/10/27 14:58:00 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_stacks	t_stacks;
typedef struct s_op		t_op;

struct	s_stacks
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
};

struct	s_op
{
	int	nra;
	int	nrra;
	int	nrb;
	int	nrrb;
	int	c1;
	int	c2;
	int	c3;
};

void	ft_error(t_stacks *stacks);
void	algo(t_stacks *stacks);

int		are_strings_equal(char *str1, char *str2);
int		find_min(int *array, int size_array);
int		find_max(int *array, int size_array);
int		is_array_sorted(int *array, int ac);

int		ft_printf(const char *str, ...);

#endif
