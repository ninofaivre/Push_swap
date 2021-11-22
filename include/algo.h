/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:10:09 by nino              #+#    #+#             */
/*   Updated: 2021/10/27 13:05:03 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

void	sort_small(t_stacks *stacks);
void	sort_big(t_stacks *stacks);

int		insert_index(int *a, int size_a, int to_insert);
int		does_b_need_swap(t_stacks *stacks);

typedef struct s_less_cost	t_less_cost;

struct s_less_cost
{
	int	number;
	int	cost;
};

void	do_op(t_stacks *stacks, void (*op)(t_stacks *stacks), int nbr);
int		n_op(int *array, int size_array, int number, char *op);
int		cost(t_stacks stacks, int number);

#endif
