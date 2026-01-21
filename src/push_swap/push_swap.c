/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:48:54 by nadoho            #+#    #+#             */
/*   Updated: 2026/01/21 23:30:42 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	process_args(char **args, t_stack **stack_a)
{
	long	val;
	int		j;

	j = 0;
	if (!args[j])
	{
		free(args);
		ft_error("Error");
	}
	while (args[j])
	{
		if (!is_integer(args[j]))
			ft_error("Error");
		val = ft_atol(args[j]);
		if (val > INT_MAX || val < INT_MIN)
			ft_error("Error");
		check_duplicates(*stack_a, (int)val);
		ft_lstadd_back(stack_a, ft_lstnew((int)val));
		free(args[j++]);
	}
	free(args);
}

void	parse_args(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	char	**args;

	i = 0;
	while (++i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			ft_error("Error");
		process_args(args, stack_a);
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
		ft_free_stack(&stack_a);
		return (0);
	}
	sort(&stack_a, &stack_b);
	return (0);
}
