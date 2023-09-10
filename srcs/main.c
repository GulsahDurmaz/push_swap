/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:15:29 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/09/09 16:43:17 by gdurmaz          ###   ########.fr       */
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

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tab;

	if (ac == 1)
		return (0);
	if (ac == 2 && !check_if_one_string(av[1]))
	{
		if (ft_count_words(av[1], ' ') > 0)
		{
			tab = ft_split(av[1], ' ');
			av = tab;
		}
		return (0);
	}
	if (!check_input_is_valid(av))
		print_error ();
	stack_a = init_stack(ac, av);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
