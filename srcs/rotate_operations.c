/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:17:46 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/08/24 14:50:20 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*current;

	if (!*stack)
		return ;
	head = *stack;
	*stack = (*stack)->next;
	head->next = NULL;
	find_stack_tail(*stack)->next = head;
	current = *stack;
	while (current)
	{
		(current)->pos -= 1;
		current = current->next;
	}
	find_stack_tail(*stack)->pos = get_stack_length(*stack);
}

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
