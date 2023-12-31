/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:17:57 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/08/24 14:48:43 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// If there are bigger sorted_pos in a, make target_sorted min bigger sorted_pos
// If there aren't makes the target_sorted pos of smallest sorted_pos in stack_a
void	get_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	int		target_pos;

	b = *stack_b;
	while (b)
	{
		target_pos = find_target_pos(*stack_a, b);
		b->target_pos = target_pos;
		b = b->next;
	}
}

// Find the closest higher value in stack A
// If no higher value found, find the lowest value in stack A
int	find_target_pos(t_stack *stack_a, t_stack *b)
{
	int	target_sorted;
	int	target_pos;

	target_sorted = INT_MAX;
	target_pos = closest_higher(stack_a, b, &target_sorted);
	if (target_sorted == INT_MAX)
		target_pos = lowest_sorted_pos(stack_a, &target_sorted);
	return (target_pos);
}

int	closest_higher(t_stack *stack_a, t_stack *b, int *target_sorted)
{
	t_stack	*a;
	int		target_pos;

	a = stack_a;
	target_pos = 0;
	while (a)
	{
		if (a->sorted_pos > b->sorted_pos && a->sorted_pos < *target_sorted)
		{
			*target_sorted = a->sorted_pos;
			target_pos = a->pos;
		}
		a = a->next;
	}
	return (target_pos);
}

int	lowest_sorted_pos(t_stack *stack_a, int *target_sorted)
{
	t_stack	*a;
	int		target_pos;

	a = stack_a;
	target_pos = 0;
	while (a)
	{
		if (a->sorted_pos < *target_sorted)
		{
			*target_sorted = a->sorted_pos;
			target_pos = a->pos;
		}
		a = a->next;
	}
	return (target_pos);
}

// cost_a is the cost of getting to the right position in stack A.
// cost_b is the cost of getting the element to the top of the B stack
// cost is negative if the node is in the bottom half
void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		length_a;
	int		length_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	length_a = get_stack_length(tmp_a);
	length_b = get_stack_length(tmp_b);
	while (tmp_b)
	{
		if (tmp_b-> pos -1 <= length_b / 2)
			tmp_b->cost_b = tmp_b->pos - 1;
		else
			tmp_b->cost_b = (length_b - tmp_b->pos +1) * -1;
		if (tmp_b->target_pos -1 <= length_a / 2)
			tmp_b->cost_a = tmp_b->target_pos -1;
		else
			tmp_b->cost_a = (length_a - tmp_b->target_pos +1) * -1;
		tmp_b = tmp_b->next;
	}
}
