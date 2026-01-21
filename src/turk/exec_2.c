#include "../../include/push_swap.h"

t_stack	*get_cheapest_node(t_stack *stack)
{
	long	cheapest;
	t_stack	*cheapest_node;

	if (!stack)
		return (NULL);
	cheapest = LONG_MAX;
	while (stack)
	{
		if (abs(stack->cost_a) + abs(stack->cost_b) < cheapest)
		{
			cheapest = abs(stack->cost_a) + abs(stack->cost_b);
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}

void	finish_rotation(t_stack **stack_a)
{
	t_stack	*min_node;
	int		len_a;

	len_a = ft_lstsize(*stack_a);
	set_current_position(*stack_a);
	min_node = *stack_a;
	while (min_node->value != get_min(*stack_a)->value)
		min_node = min_node->next;
	if (min_node->pos <= len_a / 2)
	{
		while ((*stack_a)->value != min_node->value)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != min_node->value)
			rra(stack_a);
	}
}
