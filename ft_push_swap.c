/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:21:39 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/26 07:23:39 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_struct	stack;

	if (argc == 1)
		return (0);
	stack.a = malloc(sizeof(int) * (argc - 1));
	if (!stack.a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ft_check_arguments(argc, argv, &stack) == ERROR)
	{
		write(2, "Error\n", 6);
		free(stack.a);
		return (0);
	}
	if (ft_check_duplicates(argc, &stack) == ERROR)
	{
		write(2, "Error\n", 6);
		free(stack.a);
		return (0);
	}
	return (0);
}
