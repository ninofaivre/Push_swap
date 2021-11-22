/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:46:41 by nino              #+#    #+#             */
/*   Updated: 2021/10/27 13:46:44 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_error(t_stacks *stacks)
{
	if (stacks->a)
		free(stacks->a);
	if (stacks->b)
		free(stacks->b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	stacks.size_a = ac - 1;
	stacks.size_b = 0;
	stacks.a = (int *)malloc(sizeof(int) * stacks.size_a);
	stacks.b = (int *)malloc(sizeof(int) * stacks.size_a);
	if (!stacks.a || !stacks.b || is_there_nondigitchar(av, ac))
		ft_error(&stacks);
	build_array(&stacks, av, ac);
	if (ft_is_there_double(stacks))
		ft_error(&stacks);
	if (stacks.size_a > 1 && !is_array_sorted(stacks.a, stacks.size_a))
		algo(&stacks);
	free(stacks.a);
	free(stacks.b);
	exit(EXIT_SUCCESS);
}
