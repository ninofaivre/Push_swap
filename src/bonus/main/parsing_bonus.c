/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:11:44 by nino              #+#    #+#             */
/*   Updated: 2021/10/19 17:27:07 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char	const c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

static int	ft_atoimod(t_stacks *stacks, char const *s)
{
	long int	i;
	int			minus;

	i = 0;
	minus = 1;
	while (*s && ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			minus = -1;
		s++;
	}
	if (!*s || !(*s >= '0' && *s <= '9'))
		ft_error(stacks);
	while (*s && *s >= '0' && *s <= '9' && i <= 2147483648)
		i = i * 10 + (long int)*s++ - 48;
	while (*s)
		if (*s && !ft_isspace(*s++))
			ft_error(stacks);
	if ((i > 2147483647 && minus == 1) || (-i < -2147483648 && minus == -1))
		ft_error(stacks);
	return ((int)(i * minus));
}

int	is_there_nondigitchar(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isspace(av[i][j]) && !(av[i][j] >= '0' && av[i][j] <= '9')
			&& !(av[i][j] == '+' || av[i][j] == '-'))
				return (1);
			j++;
		}
	}
	return (0);
}

void	build_array(t_stacks *stacks, char **av, int ac)
{
	int	i;

	i = 0;
	while (++i < ac)
		stacks->a[stacks->size_a - i] = ft_atoimod(stacks, av[i]);
}

int	ft_is_there_double(t_stacks stacks)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stacks.size_a)
	{
		j = i + 1;
		while (j < stacks.size_a)
		{
			if (stacks.a[j] == stacks.a[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
