/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:17:45 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/31 19:19:10 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

int	ft_is_sorted(t_stacks *stack)
{
    stack->i = 0;
	while (stack->i < stack->size_a - 1)
	{
        if (stack->a[stack->i] > stack->a[stack->i + 1])
            return (FALSE);
        stack->i++;
    }
    return (TRUE);
}

void	ft_mean(t_stacks *stack)
{
	stack->mean = 0;
	stack->i = 0;

	while (stack->i < stack->size_a)
	{
		stack->mean = stack->mean + stack->a[stack->i];
		stack->i++;
	}
	stack->mean = stack->mean / stack->size_a;
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
