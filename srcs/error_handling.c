/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:16:48 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/08/24 14:27:30 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Returns 1 if all the parameters of argv are digits*/
int	check_all_parameters_are_integers(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (0);
	return (1);
}
/*Returns 1 if all the parameters of argv are distinct*/

int	check_no_parameter_duplicated(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i + 1])
	{
		j = i + 1;
		while (av[j])
		{
			if (str_cmp_sign(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
/*Returns 1 if the input is valid:
• All the parameters are numbers
• All the parameters are distinct
• The stack is not already sorted*/

int	check_input_is_valid(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!check_all_parameters_are_integers(av[i]))
			return (0);
		i++;
	}
	if (!check_no_parameter_duplicated(av))
		return (0);
	return (1);
}

int	check_stack_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack-> next;
	}
	return (1);
}

void	print_error(void)
{
	ft_printf("%s", ERROR_MESSAGE);
	exit(1);
}
