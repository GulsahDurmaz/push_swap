/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:24:10 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/09/09 16:45:48 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define ERROR_MESSAGE "Error\n"

typedef struct stack
{
	int				pos;
	int				sorted_pos;
	int				val;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct stack	*next;
}	t_stack;

//stack_utils
t_stack		*create_node(int position, int value);
t_stack		*find_stack_tail(t_stack *list);
void		add_to_stack(t_stack **head, t_stack *new_node);
int			get_stack_length(t_stack *stack);
t_stack		*new_tail(t_stack *new_tail);

//error handling functions
int			check_if_one_string(char *av);
int			check_all_parameters_are_integers(char *av);
int			check_no_parameter_duplicated(char **av);
int			check_input_is_valid(char **av);
int			check_stack_is_sorted(t_stack *stack);

//sort functions
void		sort_three(t_stack **stack_a);
void		push_b_except_three(t_stack **stack_a, t_stack **stack_b);
void		sort_big(t_stack **stack_a, t_stack **stack_b);
void		shift_stack(t_stack **stack_a);
void		push_swap(t_stack **stack_a, t_stack **stack_b);

//big_sort functions
void		get_target_pos(t_stack **stack_a, t_stack **stack_b);
int			find_target_pos(t_stack *stack_a, t_stack *b);
int			closest_higher(t_stack *stack_a, t_stack *b, int *target_sorted);
int			lowest_sorted_pos(t_stack *stack_a, int *target_sorted);
void		get_cost(t_stack **stack_a, t_stack **stack_b);

//sort_utils
int			find_highest(t_stack *stack);
int			find_lowest_pos(t_stack **stack);
void		sorted_pos(t_stack *stack);

//do_best_move
void		do_best_move(t_stack **stack_a, t_stack **stack_b);
void		move_to_a(t_stack **a, t_stack **b, int cost_a, int cost_b);
void		rev_rot_ab(t_stack **a, t_stack **b, int *cost_a, int *cost_b);

//do_best_move_utils
void		rot_ab(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void		rotate_a_to_pos(t_stack **a, int *cost_a);
void		rotate_b_to_pos(t_stack **b, int *cost_b);

//rotate_operations
void		rotate(t_stack **stack);
void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rotate_ab(t_stack **stack_a, t_stack **stack_b);

//reverse_rotate_operations
void		reverse_rotate(t_stack **stack);
void		reverse_rotate_a(t_stack **stack_a);
void		reverse_rotate_b(t_stack **stack_b);
void		reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

//swap operations
void		swap(t_stack **stack);
void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		swap_ab(t_stack **stack_a, t_stack **stack_b);

//push operations
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_a, t_stack **stack_b);

// utils
int			abs_num(int num);
int			str_cmp_sign(const char *s1, const char *s2);
void		free_stack(t_stack **stack);
void		print_error(void);

#endif
