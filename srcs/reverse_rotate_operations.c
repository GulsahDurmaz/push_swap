/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:17:31 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/08/24 15:15:32 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Shift down all elements of stack a by 1.
// The last element becomes the first one.

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*new;
	t_stack	*current;
	int		pos;

	if (!*stack)
		return ;
	tail = find_stack_tail(*stack);
	new = new_tail(*stack);
	tail->next = *stack;
	*stack = tail;
	new->next = NULL;
	pos = 1;
	current = *stack;
	while (current)
	{
		current->pos = pos++;
		current = current->next;
	}
}

void	reverse_rotate_a(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
