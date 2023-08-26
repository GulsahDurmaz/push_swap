/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:15:29 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/08/26 14:39:07 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(int ac, char **av)
{
	t_stack		*stack_a;
	int			position;
	long int	value;

	stack_a = NULL;
	position = 1;
	value = 0;
	while (position < ac)
	{
		value = ft_atol(av[position]);
		if (value > INT_MAX || value < INT_MIN)
			print_error();
		else
			add_to_stack(&stack_a, create_node(position, (int)value));
		position++;
	}
	sorted_pos(stack_a);
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	if (!check_input_is_valid(av))
		print_error ();
	stack_a = init_stack(ac, av);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
