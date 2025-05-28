/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_single.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:00:00 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/28 21:44:21 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

int	ft_ops_single_push(int operation, t_stacks *stack)
{
	if (operation == PA && stack->size_b != 0)
	{
		ft_ops_single_reverse(RRA, stack);
		stack->a[0] = stack->b[0];
		ft_ops_single_rotate(RB, stack);
		stack->size_a++;
		stack->size_b--;
	}
	else if (operation == PB && stack->size_a != 0)
	{
		ft_ops_single_reverse(RRB, stack);
		stack->b[0] = stack->a[0];
		ft_ops_single_rotate(RA, stack);
		stack->size_a--;
		stack->size_b++;
	}
	return (SUCCESS);
}

int	ft_ops_single_reverse(int operation, t_stacks *stack)
{
	stack->i = 0;
	if (operation == RRA && stack->size_a != 0)
	{
		while (stack->i < stack->size_a - 1)
		{
			stack->temp = stack->a[0];
			stack->a[0] = stack->a[stack->i + 1];
			stack->a[stack->i + 1] = stack->temp;
			stack->i++;
		}
	}
	else if (operation == RRB && stack->size_b != 0)
	{
		while (stack->i < stack->size_b - 1)
		{
			stack->temp = stack->b[0];
			stack->b[0] = stack->b[stack->i + 1];
			stack->b[stack->i + 1] = stack->temp;
			stack->i++;
		}
	}
	return (SUCCESS);
}

int	ft_ops_single_rotate(int operation, t_stacks *stack)
{
	stack->i = stack->size_a - 1;
	if (operation == RA && stack->size_a != 0)
	{
		while (stack->i > 0)
		{
			stack->temp = stack->a[stack->size_a - 1];
			stack->a[stack->size_a - 1] = stack->a[stack->i - 1];
			stack->a[stack->i - 1] = stack->temp;
			stack->i--;
		}
	}
	else if (operation == RB && stack->size_b != 0)
	{
		while (stack->i < stack->size_b - 1)
		{
			stack->temp = stack->b[stack->size_b - 1];
			stack->b[stack->size_b - 1] = stack->b[stack->i - 1];
			stack->b[stack->i - 1] = stack->temp;
			stack->i--;
		}
	}
	return (SUCCESS);
}

int	ft_ops_single_swap(int operation, t_stacks *stack)
{
	if (operation == SA && stack->size_a >= 2)
	{
		stack->temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = stack->temp;
	}
	else if (operation == SB && stack->size_b >= 2)
	{
		stack->temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = stack->temp;
	}
	return (SUCCESS);
}
