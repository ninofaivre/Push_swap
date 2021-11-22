/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:56:40 by nino              #+#    #+#             */
/*   Updated: 2021/10/19 16:45:20 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "algo.h"
#include <stdlib.h>

void	algo(t_stacks *stacks)
{
	if (stacks->size_a <= 5)
		sort_small(stacks);
	else
		sort_big(stacks);
}
