/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:34:02 by nino              #+#    #+#             */
/*   Updated: 2021/10/27 14:59:51 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_core.h"

void	ra(t_stacks *stacks)
{
	r(stacks->a, stacks->size_a);
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	r(stacks->b, stacks->size_b);
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
	r(stacks->a, stacks->size_a);
	r(stacks->b, stacks->size_b);
	ft_printf("rr\n");
}
