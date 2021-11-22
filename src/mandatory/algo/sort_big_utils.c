/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/4/04 12:02:55 by nino              #+#    #+#             */
/*   Updated: 2021/4/04 18:04:38 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "algo.h"

void	do_op(t_stacks *stacks, void (*op)(t_stacks *stacks), int nbr)
{
	while (nbr--)
		op(stacks);
}

int	n_op(int *array, int size_array, int number, char *op)
{
	int	i;

	i = 0;
	if (op[0] == 'r' && op[1] == '\0')
		while (i < size_array && array[size_array - 1 - i] != number)
			i++;
	else if (op[0] == 'r' && op[1] == 'r')
		while (i < size_array && array[i] != number)
			i++;
	return (i + (op[0] == 'r' && op[1] == 'r'));
}

int	cost(t_stacks stacks, int number)
{
	t_op	op;

	op.nra = n_op(stacks.a, stacks.size_a, number, "r");
	op.nrra = n_op(stacks.a, stacks.size_a, number, "rr");
	op.nrb = insert_index(stacks.b, stacks.size_b, number);
	op.nrrb = stacks.size_b - insert_index(stacks.b, stacks.size_b, number);
	op.c1 = (op.nra * (op.nra > op.nrb)) + (op.nrb * (op.nra <= op.nrb));
	op.c2 = (op.nrra * (op.nrra > op.nrrb)) + (op.nrrb * (op.nrra <= op.nrrb));
	op.c3 = ((op.nra + op.nrrb) * ((op.nra + op.nrrb) < (op.nrra + op.nrb))
			+ ((op.nrra + op.nrb)
				* ((op.nra + op.nrrb) >= (op.nrra + op.nrb))));
	if (op.nra <= op.nrra && op.nrb <= op.nrrb && op.nra >= op.nrb)
		return (op.nra + 1);
	else if (op.nra <= op.nrra && op.nrb <= op.nrrb && op.nra < op.nrb)
		return (op.nrb + 1);
	if (op.nra > op.nrra && op.nrb > op.nrrb && op.nrra >= op.nrrb)
		return (op.nrra + 1);
	else if (op.nra > op.nrra && op.nrb > op.nrrb && op.nrra < op.nrrb)
		return (op.nrrb + 1);
	if (op.c1 <= op.c2 && op.c1 <= op.c3)
		return (op.c1 + 1);
	else if (op.c2 <= op.c1 && op.c2 <= op.c3)
		return (op.c2 + 1);
	return (op.c3 + 1);
}
