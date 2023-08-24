/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:18:09 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/08/24 15:15:54 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//finds highest int in the list
int	find_highest(t_stack *stack)
{
	int		highest;
	t_stack	*tmp;

	tmp = stack;
	if (tmp)
		highest = tmp->val;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if (tmp->val > highest)
			highest = tmp->val;
	}
	return (highest);
}

int	find_lowest_pos(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp_lowest;

	tmp = *stack;
	if (tmp)
		tmp_lowest = tmp;
	while (tmp)
	{
		if (tmp->sorted_pos < tmp_lowest->sorted_pos)
			tmp_lowest = tmp;
		tmp = tmp->next;
	}
	return (tmp_lowest->pos);
}

// ascending sorted position values to stack starting from 1
void	sorted_pos(t_stack *stack)
{
	int		length;
	int		highest;
	int		current_highest;
	t_stack	*current;

	length = get_stack_length(stack);
	highest = find_highest(stack);
	while (length > 0)
	{
		current = stack;
		current_highest = INT_MIN;
		while (current)
		{
			if (current->sorted_pos == 0 && current->val == highest)
			{
				current->sorted_pos = length;
				length--;
			}
			if (current->val > current_highest && current->sorted_pos == 0)
				current_highest = current->val;
			current = current->next;
		}
		highest = current_highest;
	}
}
