/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:49:14 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/29 15:49:22 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

static void	ft_ops_main(int operation, t_stacks *stack);

void	ft_sort(t_stacks *stack)
{
	stack->j = 0;
	stack->pivot = stack->size_a / 2;
	while (stack->j < stack->pivot)
	{
		ft_ops_main(PB, stack);
		stack->j++;
	}
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
	else if (operation == PA)
		ft_ops_single_push_a(stack);
	else if (operation == PB)
		ft_ops_single_push_b(stack);
	else if (operation == RRA || operation == RRB)
		ft_ops_single_reverse(operation, stack);
	else if (operation == RA || operation == RB)
		ft_ops_single_rotate(operation, stack);
	else
		ft_ops_single_swap(operation, stack);
}
