/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_single.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:00:00 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/30 10:27:41 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

void	ft_ops_single_push_a(t_stacks *stack)
{
	if (stack->size_b > 0)
	{
		stack->i = stack->size_a;
		while (stack->i > 0)
		{
			stack->a[stack->i] = stack->a[stack->i - 1];
			stack->i--;
		}
		stack->a[0] = stack->b[0];
		stack->i = 0;
		while (stack->i < stack->size_b - 1)
		{
			stack->b[stack->i] = stack->b[stack->i + 1];
			stack->i++;
		}
		stack->size_a++;
		stack->size_b--;
		write(1, "pa\n", 3);
	}
}

void	ft_ops_single_push_b(t_stacks *stack)
{
	if (stack->size_a > 0)
	{
		stack->i = stack->size_b;
		while (stack->i > 0)
		{
			stack->b[stack->i] = stack->b[stack->i - 1];
			stack->i--;
		}
		stack->b[0] = stack->a[0];
		stack->i = 0;
		while (stack->i < stack->size_a - 1)
		{
			stack->a[stack->i] = stack->a[stack->i + 1];
			stack->i++;
		}
		stack->size_a--;
		stack->size_b++;
		write(1, "pb\n", 3);
	}
}

void	ft_ops_single_reverse(int operation, t_stacks *stack)
{
	if (operation == RRA && stack->size_a > 1)
	{
		stack->temp = stack->a[stack->size_a - 1];
		stack->i = stack->size_a - 1;
		while (stack->i > 0)
		{
			stack->a[stack->i] = stack->a[stack->i - 1];
			stack->i--;
		}
		stack->a[0] = stack->temp;
		write(1, "rra\n", 4);
	}
	else if (operation == RRB && stack->size_b > 1)
	{
		stack->temp = stack->b[stack->size_b - 1];
		stack->i = stack->size_b - 1;
		while (stack->i > 0)
		{
			stack->b[stack->i] = stack->b[stack->i - 1];
			stack->i--;
		}
		stack->b[0] = stack->temp;
		write(1, "rrb\n", 4);
	}
}

void	ft_ops_single_rotate(int operation, t_stacks *stack)
{
	if (operation == RA && stack->size_a > 1)
	{
		stack->temp = stack->a[0];
		stack->i = 0;
		while (stack->i < stack->size_a - 1)
		{
			stack->a[stack->i] = stack->a[stack->i + 1];
			stack->i++;
		}
		stack->a[stack->size_a - 1] = stack->temp;
		write(1, "ra\n", 3);
	}
	else if (operation == RB && stack->size_b > 1)
	{
		stack->temp = stack->b[0];
		stack->i = 0;
		while (stack->i < stack->size_b - 1)
		{
			stack->b[stack->i] = stack->b[stack->i + 1];
			stack->i++;
		}
		stack->b[stack->size_b - 1] = stack->temp;
		write(1, "rb\n", 3);
	}
}

void	ft_ops_single_swap(int operation, t_stacks *stack)
{
	if (operation == SA && stack->size_a >= 2)
	{
		stack->temp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = stack->temp;
		write(1, "sa\n", 3);
	}
	else if (operation == SB && stack->size_b >= 2)
	{
		stack->temp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = stack->temp;
		write(1, "sb\n", 3);
	}
}
