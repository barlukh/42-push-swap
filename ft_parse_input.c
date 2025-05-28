/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:38:02 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/28 09:42:06 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

static int	ft_parse_input_allocate(t_args *arg, t_stacks *stack);

int	ft_parse_input(t_args *arg, t_stacks *stack)
{
	if (arg->argc == 1)
		return (ERROR);
	else if (arg->argc == 2 && ft_strchr(arg->argv[1], ' '))
	{
		arg->offset = FALSE;
		arg->argv = ft_split(arg->argv[1], ' ', stack);
		if (!arg->argv)
			return (ft_end(ERR_MSG, arg->argv, stack));
	}
	else
		stack->size = arg->argc - 1;
	if (ft_parse_input_allocate(arg, stack) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

// Allocates arrays for stacks and checks input arguments for errors
static int	ft_parse_input_allocate(t_args *arg, t_stacks *stack)
{
	stack->a = malloc(sizeof(int) * (stack->size));
	if (!stack->a)
	{
		if (arg->offset == TRUE)
			return (ft_end(ERR_MSG, arg->argv, stack));
		return (ft_end(ERRFREE_ARG, arg->argv, stack));
	}
	stack->b = malloc(sizeof(int) * (stack->size));
	if (!stack->b)
	{
		if (arg->offset == TRUE)
			return (ft_end(ERRFREE_A, arg->argv, stack));
		return (ft_end(ERRFREE_ARG_A, arg->argv, stack));
	}
	if (ft_check_arguments(arg->argv + arg->offset, stack) == ERROR)
	{
		if (arg->offset == TRUE)
			return (ft_end(ERRFREE_AB, arg->argv, stack));
		return (ft_end(ERRFREE_ARG_AB, arg->argv, stack));
	}
	return (SUCCESS);
}
