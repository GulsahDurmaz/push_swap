/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:17:01 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/08/24 15:16:26 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//allocates memory and creates a new node with given position and value
t_stack	*create_node(int position, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof (t_stack));
	if (!new_node)
		return (NULL);
	new_node->pos = position;
	new_node->val = value;
	new_node->sorted_pos = 0;
	new_node->target_pos = 0;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->next = NULL;
	return (new_node);
}

//takes head as input and returns a pointer to the tail of the stack
t_stack	*find_stack_tail(t_stack *tail)
{
	while (tail && tail->next)
		tail = tail->next;
	return (tail);
}

//adds node to the end of the stack and if there is no head, makes a head node
void	add_to_stack(t_stack **head, t_stack *new_node)
{
	if (!head)
		return ;
	if (!(*head))
		*head = new_node;
	else
		find_stack_tail(*head)->next = new_node;
}

//gets the length of the stack
int	get_stack_length(t_stack *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		length++;
		if (!stack->next)
			return (length);
		stack = stack->next;
	}
	return (length);
}

t_stack	*new_tail(t_stack *new_tail)
{
	t_stack	*old_tail;

	old_tail = new_tail->next;
	while (new_tail && old_tail && old_tail->next)
	{
		new_tail = new_tail->next;
		old_tail = old_tail->next;
	}
	return (new_tail);
}
