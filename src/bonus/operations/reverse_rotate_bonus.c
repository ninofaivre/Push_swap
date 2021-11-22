/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:34:49 by nino              #+#    #+#             */
/*   Updated: 2021/10/29 13:58:17 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_core.h"

void	rra(t_stacks *stacks)
{
	rev_r(stacks->a, stacks->size_a);
}

void	rrb(t_stacks *stacks)
{
	rev_r(stacks->b, stacks->size_b);
}

void	rrr(t_stacks *stacks)
{
	rev_r(stacks->a, stacks->size_a);
	rev_r(stacks->b, stacks->size_b);
}
