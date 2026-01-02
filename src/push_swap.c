/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:20:54 by luzolo            #+#    #+#             */
/*   Updated: 2026/01/02 21:12:38 by nadoho           ###   ########.fr       */
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
	fill_stack(argc, argv, a);
	for (int j = 0; j < argc - 1; j++)
		ft_printf("%d", a[j]);
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
