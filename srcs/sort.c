/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:18:25 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/08/24 14:48:00 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	highest;

	if (check_stack_is_sorted(*stack_a) == 1)
		return ;
	highest = find_highest(*stack_a);
	if ((*stack_a)->val == highest)
	{
		rotate_a(stack_a);
		if (check_stack_is_sorted(*stack_a) == 0)
			swap_a(stack_a);
	}
	else if ((*stack_a)->next->val == highest)
	{
		reverse_rotate_a(stack_a);
		if (check_stack_is_sorted(*stack_a) == 0)
			swap_a(stack_a);
	}
	else
		swap_a(stack_a);
}

// pushes and partially sorts all elements leaving only three in the stack
void	sorted_push_except_three(t_stack **s_a, t_stack **s_b)
{
	int	length;
	int	pushed;
	int	count;

	length = get_stack_length(*s_a);
	pushed = 0;
	count = 0;
	while (length > 6 && length > count && length / 2 > pushed)
	{
		if (length / 2 >= (*s_a)->sorted_pos)
		{
			push_b(s_a, s_b);
			pushed++;
		}
		else
			rotate_a(s_a);
		count++;
	}
	while (length - pushed > 3)
	{
		push_b(s_a, s_b);
		pushed++;
	}
}

// add doubles rr rrr ss by comparing stack a b and their next
void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	sorted_push_except_three(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_best_move(stack_a, stack_b);
	}
	if (!check_stack_is_sorted(*stack_a))
		shift_stack(stack_a);
}

// shifts stack a until the lowest value is at the top.
void	shift_stack(t_stack **stack_a)
{
	int	lowest;
	int	size;

	size = get_stack_length(*stack_a);
	lowest = find_lowest_pos(stack_a) -1;
	if (lowest > size / 2)
	{
		while (lowest < size)
		{
			reverse_rotate_a(stack_a);
			lowest++;
		}
	}
	else
	{
		while (lowest > 0)
		{
			rotate_a(stack_a);
			lowest--;
		}
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	length;

	length = get_stack_length(*stack_a);
	if (length == 2 && !check_stack_is_sorted(*stack_a))
		swap_a(stack_a);
	else if (length == 3)
		sort_three(stack_a);
	else if (length > 3 && !check_stack_is_sorted(*stack_a))
		sort_big(stack_a, stack_b);
}
