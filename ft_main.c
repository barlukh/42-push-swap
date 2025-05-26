/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:24:31 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/26 19:01:31 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_args		arg;
	t_stacks	stack;

	arg.argc = argc;
	arg.argv = argv;
	arg.offset = TRUE;
	if (ft_parse_input(&arg, &stack) == ERROR)
		return (0);
	
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
