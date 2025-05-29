/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:24:31 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/29 12:15:04 by bgazur           ###   ########.fr       */
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
	// ft_ops_main(SA, &stack);
	// ft_ops_main(PB, &stack);
	// ft_ops_main(PB, &stack);
	// ft_ops_main(PB, &stack);
	// ft_ops_main(RA, &stack);
	// ft_ops_main(RB, &stack);
	// ft_ops_main(RRA, &stack);
	// ft_ops_main(RRB, &stack);
	// ft_ops_main(SA, &stack);
	// ft_ops_main(PA, &stack);
	// ft_ops_main(PA, &stack);
	// ft_ops_main(PA, &stack);
	// ft_ops_main(SS, &stack);

	size_t i = 0;
	while (i < stack.size_a)
	{
		printf("%d  ", stack.a[i]);
		if (i < stack.size_b)
			printf("%d", stack.b[i]);
		printf("\n");
		i++;
	}
	printf("\nsize_a: %zu", stack.size_a);
	printf("\nsize_b: %zu\n", stack.size_b);
	// ----------------------------------------
	if (arg.offset == TRUE)
		return (ft_end(FREE_AB, arg.argv, &stack));
	return (ft_end(FREE_ARG_AB, arg.argv, &stack));
}
