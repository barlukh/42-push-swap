/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:21:39 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/26 13:27:28 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_struct	stacks;
	int			argv_offset;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv_offset = FALSE;
		argv = ft_split(argv[1], ' ', &stacks);
	}
	else
	{
		argv_offset = TRUE;
		stacks.size = argc - 1;
	}
	stacks.a = malloc(sizeof(int) * (stacks.size));
	if (!stacks.a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ft_check_arguments(argv + argv_offset, &stacks) == ERROR)
		{
			write(2, "Error\n", 6);
			free(stacks.a);
			return (0);
		}
	size_t i = 0;
	while (i < stacks.size)
	{
		printf("%d\n", stacks.a[i]);
		i++;
	}
	free(stacks.a);
	return (0);
}
