/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadoho <nadoho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:20:54 by luzolo            #+#    #+#             */
/*   Updated: 2026/01/09 21:40:18 by nadoho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	check_duplicates(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*runner;

	tmp = stack;
	while (tmp)
	{
		runner = tmp->next;
		while (runner)
		{
			if (tmp->value == runner->value)
				ft_error("Error\n");
			runner = runner->next;
		}
		tmp = tmp->next;
	}
}

void	index_stack(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*curr;
	int		match;

	ptr = *stack;
	while (ptr)
	{
		match = 0;
		curr = *stack;
		while (curr)
		{
			if (ptr->value > curr->value)
				match++;
			curr = curr->next;
		}
		ptr->index = match;
		ptr = ptr->next;
	}
}

void	parse_args(int argc, char **argv, t_stack **stack_a)
{
	long	val;
	int		i;
	char	**args;

	i = 1;
	args = argv;
	if (argc == 2)
	{
		ft_error("Not only one arg");
	}
	while (i < argc)
	{
		val = ft_atol(args[i]);
		if (val > INT_MAX || val < INT_MIN)
			ft_error("Error\n");
		ft_lstadd_back(stack_a, ft_lstnew((int)val));
		i++;
	}
	check_duplicates(*stack_a);
	index_stack(stack_a);
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
	return (0);
}
