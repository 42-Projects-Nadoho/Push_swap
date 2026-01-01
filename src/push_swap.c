/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luzolo <luzolo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:20:54 by luzolo            #+#    #+#             */
/*   Updated: 2026/01/02 00:02:29 by luzolo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	main(int argc, char **argv)
{
	int	*a;
	int	i;

	a = malloc(sizeof(int) * (argc - 1));
	if (!a)
		return (1);
	i = 0;
	while (++i < argc)
		a[i - 1] = ft_atoi(argv[i]);
	free(a);
}

void	ft_solve(int **a, int **b)
{
	int	i;

	i = 0;
	(void)b;
	while (a[i] > a[i + 1])
	{
	}
}
