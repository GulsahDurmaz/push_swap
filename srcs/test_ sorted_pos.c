/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ sorted_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:18:46 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/08/18 16:18:49 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <limits.h>
// # include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct stack
{
	int				pos;
	int				sorted_pos;
	int				val;
	struct stack	*next;
}	t_stack;

// typedef struct stack stack;

void	sorted_pos(t_stack *stack)
{
	int		length;
	int		highest;
	int		current_highest;
	t_stack	*current;

	length = 4;
	highest = 5;
	while (length > 0)
	{
		current = stack;
		current_highest = 0;
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

int main()
{
    // Create five stacks
    t_stack *head = NULL;
    t_stack *second = NULL;
    t_stack *third = NULL;
	t_stack *forth = NULL;

    // Allocate memory for stacks and assign pos
	head = (t_stack *)malloc(sizeof(t_stack));
	second = (t_stack *)malloc(sizeof(t_stack));
    third = (t_stack *)malloc(sizeof(t_stack));
	forth = (t_stack *)malloc(sizeof(t_stack));

    head->pos = 1;        // Assign pos to the first stack
	head->val = 5;
	head->sorted_pos = 0;
    head->next = second;   // Link the first stack to the second stack

    second->pos = 2;      // Assign pos to the second stack
	second->val = 1;
	second->sorted_pos = 0;
    second->next = third;  // Link the second stack to the third stack

    third->pos = 3;       // Assign pos to the third stack
	third->val = 0;
	third->sorted_pos = 0;
    third->next = forth;    // Mark the end of the list

	forth->pos = 4;       // Assign pos to the forth stack
	forth->val = 2;
	forth->sorted_pos = 0;
    forth->next = NULL;    // Mark the end of the list


    // Traverse and print the linked list
    t_stack *current = head;
	sorted_pos(current);
	while (current != NULL)
	{
        printf("%d -> ", current->sorted_pos);
        current = current->next;
    }
    printf("NULL\n");
    // Free the allocated memory for the stacks
    free(head);
    free(second);
    free(third);
	free(forth);

    return 0;
}
