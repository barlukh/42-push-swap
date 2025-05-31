/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:49:14 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/31 21:16:54 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

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
	ft_min_max(stack);
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
}

void	ft_sort_best_pair(t_stacks *stack)
{
	while (stack->locked_a != stack->a[0] || stack->locked_b != stack->b[0])
	{
		if (stack->locked_a != stack->a[0] && stack->locked_b != stack->b[0])
		{
			if (stack->dir_a == RA && stack->dir_b == RB)
				ft_ops_main(RR, stack);
			else if (stack->dir_a == RRA && stack->dir_b == RRB)
				ft_ops_main(RRR, stack);
		}
		else if (stack->locked_a != stack->a[0])
			ft_ops_main(stack->dir_a, stack);
		else if (stack->locked_b != stack->b[0])
			ft_ops_main(stack->dir_b, stack);
	}
	ft_ops_main(PA, stack);
}

void	ft_find_best_pair(t_stacks *stack)
{
	stack->i = 0;
	stack->j = 0;
	int min_diff = INT_MAX;

    while (stack->i < stack->size_b)
    {
        stack->j = 0;
        while (stack->j < stack->size_a)
        {
            int diff = stack->a[stack->j] - stack->b[stack->i];

            if (diff > 0 && diff <= min_diff)
            {
                ft_cost_dir(stack);
                int total_cost = stack->cost_a + stack->cost_b;

                if (diff < min_diff || total_cost < stack->cost_total)
                {
                    stack->locked_a = stack->a[stack->j];
                    stack->locked_b = stack->b[stack->i];
                    stack->cost_total = total_cost;
                    min_diff = diff;
                }
            }
            stack->j++;
        }
        stack->i++;
    }
}

void		ft_cost_dir(t_stacks *stack)
{
	if (stack->j < (stack->size_a - stack->j))
	{
		stack->cost_a = stack->j;
		stack->dir_a = RA;
	}
	else
	{
		stack->cost_a = stack->size_a - stack->j;
		stack->dir_a = RRA;
	}
	if (stack->i < (stack->size_b - stack->i))
	{
		stack->cost_b = stack->i;
		stack->dir_b = RB;
	}
	else
	{
		stack->cost_b = stack->size_b - stack->i;
		stack->dir_b = RRB;
	}
}
