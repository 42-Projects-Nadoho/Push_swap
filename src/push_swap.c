/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:20:54 by luzolo            #+#    #+#             */
/*   Updated: 2026/01/04 22:45:00 by antigravity      ###   ########.fr       */
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

/* Simple O(n^2) indexing for Radix sort coordinate compression */
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
		// TODO: Implement ft_split handling if needed for "1 2 3"
		// For now assume separate arguments or simple parsing
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
	if (ft_lstsize(stack_a) <= 5)
		simple_sort(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
