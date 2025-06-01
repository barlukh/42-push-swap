/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:49:14 by bgazur            #+#    #+#             */
/*   Updated: 2025/06/01 15:06:11 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

static void	ft_find_best_pair(t_stacks *stack);
static void	ft_sort_best_pair(t_stacks *stack);

void	ft_sort(t_stacks *stack)
{
	while (stack->size_a > 5)
	{
		ft_mean(stack);
		if (stack->a[0] < stack->mean)
			ft_ops_main(PB, stack);
		else
			ft_ops_main(RA, stack);
	}
	ft_max(stack);
	while (!ft_is_sorted(stack))
	{
		if (stack->a[0] > stack->a[1] && stack->a[0] != stack->max)
			ft_ops_main(SA, stack);
		else
			ft_ops_main(RR, stack);
	}
	while (stack->size_b != 0)
	{
		ft_find_best_pair(stack);
		ft_sort_best_pair(stack);
	}
	while (stack->a[stack->size_a - 1] != stack->max)
	{
		ft_ops_main(RA, stack);
	}
}

// Finds the best pair of numbers to move
static void	ft_find_best_pair(t_stacks *stack)
{
	stack->i = 0;
	while (stack->i < stack->size_b)
	{
		stack->diff_min = INT_MAX;
		stack->j = 0;
		while (stack->j < stack->size_a)
		{
			stack->diff = stack->a[stack->j] - stack->b[stack->i];
			if (stack->diff > 0 && stack->diff < stack->diff_min)
			{
				stack->locked_pos_a = stack->j;
				stack->locked_pos_b = stack->i;
				stack->diff_min = stack->diff;
			}
			stack->j++;
		}
		ft_cost_dir(stack);
		if (stack->i == 0 || stack->cost_a + stack->cost_b < stack->cost_total)
		{
			stack->locked_num_a = stack->a[stack->locked_pos_a];
			stack->locked_num_b = stack->b[stack->locked_pos_b];
			stack->cost_total = stack->cost_a + stack->cost_b;
		}
		stack->i++;
	}
}

// Moves the best pair of numbers into their correct position
static void	ft_sort_best_pair(t_stacks *stack)
{
	while (stack->locked_num_a != stack->a[0]
		|| stack->locked_num_b != stack->b[0])
	{
		if (stack->locked_num_a != stack->a[0]
			&& stack->locked_num_b != stack->b[0])
		{
			if (stack->dir_a == RA && stack->dir_b == RB)
				ft_ops_main(RR, stack);
			else if (stack->dir_a == RRA && stack->dir_b == RRB)
				ft_ops_main(RRR, stack);
		}
		if (stack->locked_num_a != stack->a[0])
			ft_ops_main(stack->dir_a, stack);
		if (stack->locked_num_b != stack->b[0])
			ft_ops_main(stack->dir_b, stack);
	}
	ft_ops_main(PA, stack);
}
