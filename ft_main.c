/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:24:31 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/26 20:03:05 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

static int	ft_parse_input(t_args *arg, t_stacks *stack);

int	main(int argc, char **argv)
{
	t_args		arg;
	t_stacks	stack;

	arg.argc = argc;
	arg.argv = argv;
	arg.offset = TRUE;
	if (ft_parse_input(&arg, &stack) == ERROR)
		return (0);
	// REMEMBER TO REMOVE BEFORE SUBMISSION!
	size_t i = 0;
	while (i < stack.size)
	{
		printf("%d\n", stack.a[i]);
		i++;
	}
	if (arg.offset == TRUE)
		return (ft_end(FREESTCK, arg.argv, &stack));
	return (ft_end(FREEARGSTCK, arg.argv, &stack));
}

// Parses input arguments and checks for errors
static int	ft_parse_input(t_args *arg, t_stacks *stack)
{
	if (arg->argc == 1)
		return (ERROR);
	else if (arg->argc == 2 && ft_strchr(arg->argv[1], ' '))
	{
		arg->offset = FALSE;
		arg->argv = ft_split(arg->argv[1], ' ', stack);
		if (!arg->argv)
			return (ft_end(ERRONLY, arg->argv, stack));
	}
	else
		stack->size = arg->argc - 1;
	stack->a = malloc(sizeof(int) * (stack->size));
	if (!stack->a)
	{
		if (arg->offset == TRUE)
			return (ft_end(ERRONLY, arg->argv, stack));
		return (ft_end(ERRFREEARG, arg->argv, stack));
	}
	if (ft_check_arguments(arg->argv + arg->offset, stack) == ERROR)
	{
		if (arg->offset == TRUE)
			return (ft_end(ERRFREESTCK, arg->argv, stack));
		return (ft_end(ERRFREEARGSTCK, arg->argv, stack));
	}
	return (SUCCESS);
}
