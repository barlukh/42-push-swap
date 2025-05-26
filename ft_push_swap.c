/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:21:39 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/26 15:02:22 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_struct	stack;
	int			argv_offset;

	if (argc == 1)
		return (0);
	else if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		argv_offset = FALSE;
		argv = ft_split(argv[1], ' ', &stack);
		if (!argv)
			return (ft_exit(ERRONLY, argv, stack));
	}
	else
	{
		argv_offset = TRUE;
		stack.size = argc - 1;
	}
	stack.a = malloc(sizeof(int) * (stack.size));
	if (!stack.a)
	{
		if (argv_offset == TRUE)
			return (ft_exit(ERRONLY, argv, stack));
		return (ft_exit(ERRFREEARG, argv, stack));
	}
	if (ft_check_arguments(argv + argv_offset, &stack) == ERROR)
	{
		if (argv_offset == TRUE)
			return (ft_exit(ERRFREESTCK, argv, stack));
		return (ft_exit(ERRFREEARGSTCK, argv, stack));
	}
	size_t i = 0;
	while (i < stack.size)
	{
		printf("%d\n", stack.a[i]);
		i++;
	}
	if (argv_offset == TRUE)
		return (ft_exit(FREESTCK, argv, stack));
	return (ft_exit(FREEARGSTCK, argv, stack));
	return (0);
}
