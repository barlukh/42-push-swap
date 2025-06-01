/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:24:31 by bgazur            #+#    #+#             */
/*   Updated: 2025/06/01 15:03:25 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

int	main(int argc, char **argv)
{
	t_args		arg;
	t_stacks	stack;

	arg.argc = argc;
	arg.argv = argv;
	arg.offset = TRUE;
	if (ft_parse_input(&arg, &stack) == ERROR)
		return (ERROR);
	ft_sort(&stack);
	// REMEMBER TO REMOVE BEFORE SUBMISSION!
	size_t i = 0;
	while (i < stack.size_a)
	{
		printf("%d ", stack.a[i]);
		i++;
	}
	i = 0;
	printf("\n");
	while (i < stack.size_b)
	{
		printf("%d ", stack.b[i]);
		i++;
	}
	printf("\nsize_a: %zu", stack.size_a);
	printf("\nsize_b: %zu", stack.size_b);
	printf("\ncost_a: %d", stack.cost_a);
	printf("\ncost_b: %d", stack.cost_b);
	printf("\nlocked_a: %d", stack.locked_num_a);
	printf("\nlocked_b: %d\n", stack.locked_num_b);
	// ----------------------------------------
	if (arg.offset == TRUE)
		return (ft_end(FREE_AB, arg.argv, &stack));
	return (ft_end(FREE_ARG_AB, arg.argv, &stack));
}
