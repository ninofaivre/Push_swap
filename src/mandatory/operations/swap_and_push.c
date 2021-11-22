/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:32:47 by nino              #+#    #+#             */
/*   Updated: 2021/10/27 14:59:46 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_core.h"

void	sa(t_stacks *stacks)
{
	s(stacks->a, stacks->size_a);
	ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	s(stacks->b, stacks->size_b);
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	s(stacks->a, stacks->size_a);
	s(stacks->b, stacks->size_b);
	ft_printf("ss\n");
}

void	pa(t_stacks *stacks)
{
	p(stacks->b, &stacks->size_b, stacks->a, &stacks->size_a);
	ft_printf("pa\n");
}

void	pb(t_stacks *stacks)
{
	p(stacks->a, &stacks->size_a, stacks->b, &stacks->size_b);
	ft_printf("pb\n");
}
