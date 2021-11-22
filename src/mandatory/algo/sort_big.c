/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:11:55 by nino              #+#    #+#             */
/*   Updated: 2021/10/27 13:46:19 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "algo.h"

static t_op	put_less_cost_a_b_ann(t_stacks *stacks, int number)
{
	t_op	op;

	op.nra = n_op(stacks->a, stacks->size_a, number, "r");
	op.nrra = n_op(stacks->a, stacks->size_a, number, "rr");
	op.nrb = insert_index(stacks->b, stacks->size_b, number);
	op.nrrb = stacks->size_b - insert_index(stacks->b, stacks->size_b, number);
	op.c1 = (op.nra * (op.nra > op.nrb)) + (op.nrb * (op.nra <= op.nrb));
	op.c2 = (op.nrra * (op.nrra > op.nrrb)) + (op.nrrb * (op.nrra <= op.nrrb));
	op.c3 = ((op.nra + op.nrrb) * ((op.nra + op.nrrb) < (op.nrra + op.nrb)))
		+ ((op.nrra + op.nrb) * ((op.nra + op.nrrb) >= (op.nrra + op.nrb)));
	if ((op.nra >= op.nrb) && (op.c1 <= op.c2 && op.c1 <= op.c3))
	{
		do_op(stacks, &ra, (op.nra - op.nrb));
		do_op(stacks, &rr, op.nrb);
	}
	else if ((op.nra < op.nrb) && (op.c1 <= op.c2 && op.c1 <= op.c3))
	{
		do_op(stacks, &rb, (op.nrb - op.nra));
		do_op(stacks, &rr, op.nra);
	}
	return (op);
}

static void	put_less_cost_a_b(t_stacks *stacks, int number)
{
	t_op	op;

	op = put_less_cost_a_b_ann(stacks, number);
	if ((op.nrra >= op.nrrb) && (op.c2 <= op.c1 && op.c2 <= op.c3))
	{
		do_op(stacks, &rra, (op.nrra - op.nrrb));
		do_op(stacks, &rrr, op.nrrb);
	}
	else if ((op.nrra < op.nrrb) && (op.c2 <= op.c1 && op.c2 <= op.c3))
	{
		do_op(stacks, &rrb, (op.nrrb - op.nrra));
		do_op(stacks, &rrr, op.nrra);
	}
	else if (((op.nra + op.nrrb) < (op.nrra + op.nrb))
		&& (op.c3 <= op.c2 && op.c3 <= op.c1))
	{
		do_op(stacks, &ra, op.nra);
		do_op(stacks, &rrb, op.nrrb);
	}
	else if (((op.nra + op.nrrb) >= (op.nrra + op.nrb))
		&& (op.c3 <= op.c2 && op.c3 <= op.c1))
	{
		do_op(stacks, &rra, op.nrra);
		do_op(stacks, &rb, op.nrb);
	}
}

static void	put_a_b(t_stacks *stacks)
{
	int			i;
	t_less_cost	less_cost;

	while (stacks->size_a != 0)
	{
		i = 0;
		less_cost.number = stacks->a[stacks->size_a - 1];
		less_cost.cost = cost(*stacks, stacks->a[stacks->size_a - 1]);
		while (stacks->size_a - 1 - i)
		{
			if (cost(*stacks, stacks->a[i]) < less_cost.cost)
			{
				less_cost.number = stacks->a[i];
				less_cost.cost = cost(*stacks, stacks->a[i]);
			}
			i++;
		}
		put_less_cost_a_b(stacks, less_cost.number);
		pb(stacks);
	}
}

static void	put_b_a(t_stacks *stacks)
{
	int	n_r;
	int	n_rr;

	while (stacks->size_b != 0)
	{
		n_r = n_op(stacks->b, stacks->size_b,
				stacks->b[find_max(stacks->b, stacks->size_b)], "r");
		n_rr = n_op(stacks->b, stacks->size_b,
				stacks->b[find_max(stacks->b, stacks->size_b)], "rr");
		if (n_r <= n_rr)
			while (n_r--)
				rb(stacks);
		else
			while (n_rr--)
				rrb(stacks);
		pa(stacks);
	}
}

void	sort_big(t_stacks *stacks)
{
	pb(stacks);
	pb(stacks);
	put_a_b(stacks);
	put_b_a(stacks);
}
