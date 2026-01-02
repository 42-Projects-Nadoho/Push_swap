/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilialisation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:53:30 by luzolo            #+#    #+#             */
/*   Updated: 2026/01/02 21:15:26 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int is_valid_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

void	fill_stack(int ac, char **av, int *a)
{
	int		i;
	long	tmp;

	i = 0;
	while (++i < ac)
	{
		if (!is_valid_number(av[i]))
		{
			free(a);
			ft_return_error();
		}
		tmp = ft_atoi(av[i]);
		a[i - 1] = (int)tmp;
	}
}