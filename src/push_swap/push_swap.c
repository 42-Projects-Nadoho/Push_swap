/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:20:54 by luzolo            #+#    #+#             */
/*   Updated: 2026/01/20 15:51:16 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	parse_args(int argc, char **argv, t_stack **stack_a)
{
	long	val;
	int		i;
	int		j;
	char	**args;

	i = 1;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			ft_error("Error\n");
		j = 0;
		while (*args)
		{
			val = ft_atol(args[j]);
			if (val > INT_MAX || val < INT_MIN)
				ft_error("Error\n");
			ft_lstadd_back(stack_a, ft_lstnew((int)val));
			free(args[j]);
			j++;
		}
		free(args);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	parse_args(argc, argv, &stack_a);
	if (is_sorted(&stack_a))
	{
		ft_printf("sorted");
		ft_free_stack(&stack_a);
		return (0);
	}
	sort(&stack_a, &stack_b);
	return (0);
}
