/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:25:22 by nino              #+#    #+#             */
/*   Updated: 2021/10/29 13:46:46 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "algo.h"

int	are_strings_equal(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1 += 1;
		str2 += 1;
	}
	if (*str1 || *str2)
		return (0);
	return (1);
}

int	find_min(int *array, int size_array)
{
	int	i;
	int	index_min;

	i = 0;
	index_min = 0;
	while (i < size_array)
	{
		if (array[i] < array[index_min])
			index_min = i;
		i++;
	}
	return (index_min);
}

int	find_max(int *array, int size_array)
{
	int	i;
	int	index_max;

	i = 0;
	index_max = 0;
	while (i < size_array)
	{
		if (array[i] > array[index_max])
			index_max = i;
		i++;
	}
	return (index_max);
}

int	is_array_sorted(int *array, int size_array)
{
	while (--size_array)
		if (array[size_array] > array[size_array - 1])
			return (0);
	return (1);
}
