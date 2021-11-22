/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:34:02 by nino              #+#    #+#             */
/*   Updated: 2021/10/29 13:35:20 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_core.h"

void	ra(t_stacks *stacks)
{
	r(stacks->a, stacks->size_a);
}

void	rb(t_stacks *stacks)
{
	r(stacks->b, stacks->size_b);
}

void	rr(t_stacks *stacks)
{
	r(stacks->a, stacks->size_a);
	r(stacks->b, stacks->size_b);
}
