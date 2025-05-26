/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:21:39 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/26 18:59:00 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_parse_input(t_args *arg, t_stacks *stack)
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
