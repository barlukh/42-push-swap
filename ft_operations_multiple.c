/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_multiple.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:59:27 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/29 10:30:54 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

void	ft_ops_multiple_reverse(t_stacks *stack)
{
	if (stack->size_a > 1)
	{
		stack->temp = stack->a[0];
		stack->i = 0;
		while (stack->i < stack->size_a - 1)
		{
			stack->a[stack->i] = stack->a[stack->i + 1];
			stack->i++;
		}
		stack->a[stack->size_a - 1] = stack->temp;
	}
	if (stack->size_b > 1)
	{
		stack->temp = stack->b[0];
		stack->i = 0;
		while (stack->i < stack->size_b - 1)
		{
			stack->b[stack->i] = stack->b[stack->i + 1];
			stack->i++;
		}
		stack->b[stack->size_b - 1] = stack->temp;
	}
}

void	ft_ops_multiple_rotate(t_stacks *stack)
{
	if (stack->size_a > 1)
	{
		stack->temp = stack->a[stack->size_a - 1];
		stack->i = stack->size_a - 1;
		while (stack->i > 0)
		{
			stack->a[stack->i] = stack->a[stack->i - 1];
			stack->i--;
		}
		stack->a[0] = stack->temp;
	}
	else if (stack->size_b > 1)
	{
		stack->temp = stack->b[stack->size_b - 1];
		stack->i = stack->size_b - 1;
		while (stack->i > 0)
		{
			stack->b[stack->i] = stack->b[stack->i - 1];
			stack->i--;
		}
		stack->b[0] = stack->temp;
	}
}

void	ft_ops_multiple_swap(t_stacks *stack)
{
	if (stack->size_a >= 2)
	{
		stack->temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = stack->temp;
	}
	if (stack->size_b >= 2)
	{
		stack->temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = stack->temp;
	}
}
