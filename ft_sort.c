/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:49:14 by bgazur            #+#    #+#             */
/*   Updated: 2025/06/02 14:21:08 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

static void	ft_find_best_pair(t_stacks *stack);
static void	ft_lock_best_pair(t_stacks *stack);
static void	ft_sort_best_pair(t_stacks *stack);
static void	ft_sort_three(t_stacks *stack);

void	ft_sort(t_stacks *stack)
{
	while (stack->size_a > 3)
	{
		ft_mean(stack);
		if (stack->a[0] < stack->mean)
			ft_ops_main(PB, stack);
		else
			ft_ops_main(RA, stack);
	}
	ft_sort_three(stack);
	while (stack->size_b != 0)
	{
		ft_find_best_pair(stack);
		ft_sort_best_pair(stack);
	}
	ft_max_min(stack);
	stack->i = 0;
	while (stack->a[stack->i] != stack->min)
		stack->i++;
	if (stack->i < (stack->size_a - stack->i))
		stack->dir_a = RA;
	else
		stack->dir_a = RRA;
	while (stack->a[0] != stack->min)
		ft_ops_main(stack->dir_a, stack);
}

// Finds the best pair of numbers to move
static void	ft_find_best_pair(t_stacks *stack)
{
	stack->i = 0;
	while (stack->i < stack->size_b)
	{
		stack->diff_min = LLONG_MAX;
		stack->j = 0;
		while (stack->j < stack->size_a)
		{
			stack->diff = (long long)stack->a[stack->j]
				- (long long)stack->b[stack->i];
			if (stack->diff > 0 && stack->diff < stack->diff_min)
			{
				stack->locked_pos_a = stack->j;
				stack->locked_pos_b = stack->i;
				stack->diff_min = stack->diff;
			}
			stack->j++;
		}
		ft_movement_cost(stack);
		ft_lock_best_pair(stack);
		stack->i++;
	}
}

// Checks if the new pair of numbers is the best pair and saves its attributes
static void	ft_lock_best_pair(t_stacks *stack)
{
	if (stack->i == 0 || stack->cost_a + stack->cost_b < stack->cost_total)
	{
		stack->cost_total = stack->cost_a + stack->cost_b;
		stack->locked_dir_a = stack->dir_a;
		stack->locked_dir_b = stack->dir_b;
		stack->locked_num_a = stack->a[stack->locked_pos_a];
		stack->locked_num_b = stack->b[stack->locked_pos_b];
	}
}

// Moves the best pair of numbers into its correct position
static void	ft_sort_best_pair(t_stacks *stack)
{
	while (stack->locked_num_a != stack->a[0]
		|| stack->locked_num_b != stack->b[0])
	{
		if (stack->locked_num_a != stack->a[0]
			&& stack->locked_num_b != stack->b[0])
		{
			if (stack->locked_dir_a == RA && stack->locked_dir_b == RB)
				ft_ops_main(RR, stack);
			else if (stack->dir_a == RRA && stack->locked_dir_b == RRB)
				ft_ops_main(RRR, stack);
		}
		if (stack->locked_num_a != stack->a[0])
			ft_ops_main(stack->locked_dir_a, stack);
		if (stack->locked_num_b != stack->b[0])
			ft_ops_main(stack->locked_dir_b, stack);
	}
	ft_ops_main(PA, stack);
}

// Checks and sorts the largest three values left in the stack 'a'
static void	ft_sort_three(t_stacks *stack)
{
	ft_max_min(stack);
	if (!ft_is_sorted(stack))
	{
		if (stack->a[0] == stack->min)
		{
			ft_ops_main(RA, stack);
			ft_ops_main(SA, stack);
		}
		else if (stack->a[0] == stack->max && stack->a[2] == stack->min)
			ft_ops_main(SA, stack);
		else if (stack->a[1] == stack->min && stack->a[2] == stack->max)
			ft_ops_main(SA, stack);
	}
}
