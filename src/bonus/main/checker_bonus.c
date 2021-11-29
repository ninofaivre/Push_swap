/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaivre <nfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:46:41 by nino              #+#    #+#             */
/*   Updated: 2021/11/29 13:16:57 by nfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"
#include "parsing.h"
#include "operations.h"
#include <unistd.h>
#include <stdlib.h>

static int	do_stdin_op(t_stacks *stacks, char *str)
{
	if (are_strings_equal(str, "sa\n"))
		sa(stacks);
	else if (are_strings_equal(str, "sb\n"))
		sb(stacks);
	else if (are_strings_equal(str, "ss\n"))
		ss(stacks);
	else if (are_strings_equal(str, "pa\n"))
		pa(stacks);
	else if (are_strings_equal(str, "pb\n"))
		pb(stacks);
	else if (are_strings_equal(str, "ra\n"))
		ra(stacks);
	else if (are_strings_equal(str, "rb\n"))
		rb(stacks);
	else if (are_strings_equal(str, "rr\n"))
		rr(stacks);
	else if (are_strings_equal(str, "rra\n"))
		rra(stacks);
	else if (are_strings_equal(str, "rrb\n"))
		rrb(stacks);
	else if (are_strings_equal(str, "rrr\n"))
		rrr(stacks);
	else
		return (-1);
	return (0);
}

void	ft_error(t_stacks *stacks)
{
	if (stacks->a)
		free(stacks->a);
	if (stacks->b)
		free(stacks->b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	ft_parse_stdin(t_stacks *stacks)
{
	char	*str;

	str = get_next_line(0);
	if (str && (stacks->size_a == 0
			|| is_array_sorted(stacks->a, stacks->size_a)))
	{
		free(str);
		get_next_line(-1);
		ft_error(stacks);
	}
	while (str)
	{
		if (do_stdin_op(stacks, str) == -1)
		{
			free(str);
			get_next_line(-1);
			ft_error(stacks);
		}
		free(str);
		str = get_next_line(0);
	}
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
	ft_parse_stdin(&stacks);
	if (stacks.size_a != 0 && is_array_sorted(stacks.a, stacks.size_a))
		ft_printf("OK\n");
	else if (stacks.size_a != 0)
		ft_printf("KO\n");
	free(stacks.a);
	free(stacks.b);
	exit(EXIT_SUCCESS);
}
