/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:57:23 by nino              #+#    #+#             */
/*   Updated: 2021/10/20 17:42:09 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	s(int *array, int size_array)
{
	int	tmp;

	if (size_array < 2)
		return ;
	tmp = array[size_array - 1];
	array[size_array - 1] = array[size_array - 2];
	array[size_array - 2] = tmp;
}

void	p(int *array1, int *size_array1, int *array2, int *size_array2)
{
	array2[*size_array2] = array1[*size_array1 - 1];
	*size_array1 -= 1;
	*size_array2 += 1;
}

void	r(int *array, int size_array)
{
	int	i;
	int	tmp;

	i = size_array - 1;
	tmp = array[size_array - 1];
	while (i--)
		array[i + 1] = array[i];
	array[0] = tmp;
}

void	rev_r(int *array, int size_array)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = array[i];
	while (i++ < size_array - 1)
		array[i - 1] = array[i];
	array[size_array - 1] = tmp;
}
