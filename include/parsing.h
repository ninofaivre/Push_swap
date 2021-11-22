/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:14:28 by nino              #+#    #+#             */
/*   Updated: 2021/10/19 16:17:28 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		is_there_nondigitchar(char **av, int ac);
void	build_array(t_stacks *stacks, char **av, int ac);
int		ft_is_there_double(t_stacks stacks);

#endif
