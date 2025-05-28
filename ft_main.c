/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:24:31 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/28 09:49:00 by bgazur           ###   ########.fr       */
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
	// REMEMBER TO REMOVE BEFORE SUBMISSION!
	size_t i = 0;
	while (i < stack.size)
	{
		printf("%d\n", stack.a[i]);
		i++;
	}
	// ----------------------------------------
	if (arg.offset == TRUE)
		return (ft_end(FREE_AB, arg.argv, &stack));
	return (ft_end(FREE_ARG_AB, arg.argv, &stack));
}
