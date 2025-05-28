/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_multiple.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:59:27 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/28 18:41:19 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

int	ft_ops_multiple_reverse(t_stacks *stack)
{
	return (SUCCESS);
}

int	ft_ops_multiple_rotate(t_stacks *stack)
{
	return (SUCCESS);
}

int	ft_ops_multiple_swap(t_stacks *stack)
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
