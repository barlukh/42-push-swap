/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:24:31 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/28 18:28:45 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

static void	ft_ops_main(int operation, t_stacks *stack);

int	main(int argc, char **argv)
{
	t_args		arg;
	t_stacks	stack;

	arg.argc = argc;
	arg.argv = argv;
	arg.offset = TRUE;
	if (ft_parse_input(&arg, &stack) == ERROR)
		return (ERROR);
	// REMEMBER TO REMOVE BEFORE SUBMISSION!
	size_t i = 0;
	while (i < stack.size_a)
	{
		printf("%d\n", stack.a[i]);
		i++;
	}
	printf("\nsize_a: %zu", stack.size_a);
	printf("\nsize_b: %zu\n", stack.size_b);
	// ----------------------------------------
	if (arg.offset == TRUE)
		return (ft_end(FREE_AB, arg.argv, &stack));
	return (ft_end(FREE_ARG_AB, arg.argv, &stack));
}

// Calls relevant function based on the operation passed
void	ft_ops_main(int operation, t_stacks *stack)
{
	if (operation == RRR)
		ft_ops_multiple_reverse(stack);
	else if (operation == RR)
		ft_ops_multiple_rotate(stack);
	else if (operation == SS)
		ft_ops_multiple_swap(stack);
	else if (operation == PA || operation == PB)
		ft_ops_single_push(operation, stack);
	else if (operation == RRA || operation == RRB)
		ft_ops_single_reverse(operation, stack);
	else if (operation == RA || operation == RB)
		ft_ops_single_rotate(operation, stack);
	else
		ft_ops_single_swap(operation, stack);
}
