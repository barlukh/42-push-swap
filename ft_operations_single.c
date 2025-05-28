/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_single.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:00:00 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/28 18:41:07 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

int	ft_ops_single_push(int operation, t_stacks *stack)
{
	return (SUCCESS);
}

int	ft_ops_single_reverse(int operation, t_stacks *stack)
{
	return (SUCCESS);
}

int	ft_ops_single_rotate(int operation, t_stacks *stack)
{
	return (SUCCESS);
}

int	ft_ops_single_swap(int operation, t_stacks *stack)
{
	if (operation == SA)
	{
		if (stack->size_a >= 2)
		{
			stack->temp = stack->a[0];
			stack->a[0] = stack->a[1];
			stack->a[1] = stack->temp;
		}
	}
	else
	{
		if (stack->size_b >= 2)
		{
			stack->temp = stack->b[0];
			stack->b[0] = stack->b[1];
			stack->b[1] = stack->temp;
		}
	}
	return (SUCCESS);
}
