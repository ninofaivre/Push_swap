/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:08:09 by nino              #+#    #+#             */
/*   Updated: 2021/10/20 18:37:31 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "algo.h"

static void	sort_2(t_stacks *stacks)
{
	sa(stacks);
	return ;
}

static void	sort_3(t_stacks *stacks)
{
	if ((stacks->a[1] < stacks->a[2] && stacks->a[1] < stacks->a[0]
			&& stacks->a[2] < stacks->a[0]) || (stacks->a[1] > stacks->a[0]
			&& stacks->a[1] < stacks->a[2]) || (stacks->a[1] > stacks->a[0]
			&& stacks->a[1] > stacks->a[2] && stacks->a[2] < stacks->a[0]))
	{
		if (does_b_need_swap(stacks))
			ss(stacks);
		else
			sa(stacks);
	}
	if (stacks->a[1] < stacks->a[0] && stacks->a[1] < stacks->a[2]
		&& stacks->a[2] > stacks->a[0])
	{
		if (does_b_need_swap(stacks))
			rr(stacks);
		else
			ra(stacks);
	}
	else if (stacks->a[1] > stacks->a[0] && stacks->a[1] > stacks->a[2]
		&& stacks->a[2] > stacks->a[0] && does_b_need_swap(stacks))
		rrr(stacks);
	else if (stacks->a[1] > stacks->a[0] && stacks->a[1] > stacks->a[2]
		&& stacks->a[2] > stacks->a[0] && !does_b_need_swap(stacks))
		rra(stacks);
}

static void	insert_1(t_stacks *stacks)
{
	if (stacks->b[0] < stacks->a[stacks->size_a - 1])
		pa(stacks);
	while (stacks->size_b)
	{
		if (stacks->b[stacks->size_b - 1] > stacks->a[0])
			pa(stacks);
		else
			rra(stacks);
	}
}

static void	insert_2(t_stacks *stacks)
{
	if (stacks->b[1] < stacks->a[stacks->size_a - 1])
		pa(stacks);
	if (stacks->b[0] < stacks->a[stacks->size_a - 1])
	{
		if (stacks->size_b == 2)
			sb(stacks);
		pa(stacks);
	}
	if (stacks->size_b == 2 && stacks->b[0] > stacks->b[1])
		sb(stacks);
	while (stacks->size_b)
	{
		if (stacks->b[stacks->size_b - 1] > stacks->a[0])
			pa(stacks);
		else
			rra(stacks);
	}
}

void	sort_small(t_stacks *stacks)
{
	if (stacks->size_a == 2)
		return (sort_2(stacks));
	while (stacks->size_a != 3)
		pb(stacks);
	sort_3(stacks);
	if (stacks->size_b == 1)
		insert_1(stacks);
	else if (stacks->size_b == 2)
		insert_2(stacks);
	if (find_min(stacks->a, stacks->size_a) < ((stacks->size_a - 1) / 2))
		while (find_min(stacks->a, stacks->size_a) != (stacks->size_a - 1))
			rra(stacks);
	else
		while (find_min(stacks->a, stacks->size_a) != (stacks->size_a - 1))
			ra(stacks);
}
