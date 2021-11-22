/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:40:53 by nino              #+#    #+#             */
/*   Updated: 2021/10/19 23:25:11 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insert_index(int *array, int size_array, int number)
{
	int	i;

	i = find_min(array, size_array);
	if (number < array[find_min(array, size_array)])
		return (size_array - find_min(array, size_array));
	else if (number > array[find_max(array, size_array)])
		return (size_array - 1 - find_max(array, size_array));
	while (i < size_array && number > array[i])
		i++;
	if (i < size_array && number < array[i])
		return (size_array - i);
	i = 0;
	while (i != find_min(array, size_array) && number > array[i])
		i++;
	return (size_array - i);
}

int	does_b_need_swap(t_stacks stacks)
{
	return ((stacks.size_b == 2)
		&& ((stacks.b[1] > stacks.a[find_min(stacks.a, stacks.size_a)]
				&& stacks.b[0] > stacks.b[1])
			|| (stacks.b[1] < stacks.a[find_min(stacks.a, stacks.size_a)]
				&& stacks.b[0] < stacks.a[find_min(stacks.a, stacks.size_a)]
				&& stacks.b[0] > stacks.b[1])
			|| (stacks.b[1] > stacks.a[find_min(stacks.a, stacks.size_a)]
				&& stacks.b[0]
				< stacks.a[find_min(stacks.a, stacks.size_a)])));
}
