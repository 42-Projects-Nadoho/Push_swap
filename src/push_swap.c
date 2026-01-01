/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luzolo <luzolo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:20:54 by luzolo            #+#    #+#             */
/*   Updated: 2026/01/01 23:02:51 by luzolo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	main(int argc, char **argv)
{
	int	*a;
	//int	*b;

	a = malloc(sizeof(int) * (argc - 1));
	if (!a)
		return (1);
	for (int i = 1; i < argc; i++)
	{
		a[i - 1] = ft_atoi(argv[i]);
	}
	for (int i = 0; i < argc - 1; i++)
	{
		ft_printf("%d", a[i]);
	}
	free(a);
	//ft_solve(&a, &b);
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

void	sa(void)
{
}

void	sb()
{
	ft_printf("hello");
}

void	ss()
{
}
