/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 23:30:27 by luzolo            #+#    #+#             */
/*   Updated: 2026/01/03 17:56:23 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

void	ft_return_error(void)
{
	ft_printf("Erreur");
	
	exit(1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	res = 0;
	i = -1;
	sign = 1;
	if (nptr[++i] == '-' || nptr[i] == '+')
		if (nptr[i] == '-')
			sign = sign * -1;
	while (ft_isdigit(nptr[i]))
		res = res * 10 + (nptr[i++] - '0');
	if (!ft_isdigit(nptr[i]) && nptr[i] != '\0')
		ft_return_error();
	return (res * sign);
}
