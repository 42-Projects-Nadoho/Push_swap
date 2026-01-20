/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilialisation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:53:30 by luzolo            #+#    #+#             */
/*   Updated: 2026/01/20 15:51:21 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	parse_args(int argc, char **argv, t_stack **stack_a)
{
	long	val;
	int		i;
	char	**args;

	i = 1;
	args = argv;
	if (argc == 2)
	{
		args = ft_split(args[1], ' ');
	}
	while (i < argc)
	{
		val = ft_atol(args[i]);
		if (val > INT_MAX || val < INT_MIN)
			ft_error("Error\n");
		ft_lstadd_back(stack_a, ft_lstnew((int)val));
		i++;
	}
	index_stack(stack_a);
}
