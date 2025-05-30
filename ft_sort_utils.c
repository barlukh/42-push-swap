/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:17:45 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/30 11:18:24 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

void	ft_median(t_stacks *stack)
{
	ft_memcpy(stack->b, stack->a, stack->size_a * sizeof(int));
	stack->i = 0;
	stack->j = stack->size_a - 1;
	while (stack->j > 0)
	{
		while (stack->i < (stack->size_a - 1))
		{
			if (stack->b[stack->i + 1] < stack->b[stack->i])
			{
				stack->temp = stack->b[stack->i];
				stack->b[stack->i] = stack->b[stack->i + 1];
				stack->b[stack->i + 1] = stack->temp;
			}
			stack->i++;
		}
		stack->i = 0;
		stack->j--;
	}
	if (stack->size_a % 2 == 0)
		stack->median = (stack->b[stack->size_a / 2 - 1]
				+ stack->b[stack->size_a / 2]) / 2;
	else
		stack->median = stack->b[stack->size_a / 2];
}

void	ft_min_max(t_stacks *stack)
{
	stack->i = 0;
	stack->min = stack->a[0];
	stack->max = stack->a[0];
	while (stack->i < stack->size_a)
	{
		if (stack->a[stack->i] < stack->min)
			stack->min = stack->a[stack->i];
		if (stack->a[stack->i] > stack->max)
			stack->max = stack->a[stack->i];
		stack->i++;
	}
}

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
