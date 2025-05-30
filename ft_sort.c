/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:49:14 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/30 11:49:18 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

void	ft_sort(t_stacks *stack)
{
	size_t	flag;

	flag = 0;
	stack->j = 0;
	stack->k = stack->size_a;
	ft_median(stack);
	ft_min_max(stack);
	while (stack->j < stack->k)
	{
		if (stack->a[0] <= stack->median)
			ft_ops_main(PB, stack);
		else
			ft_ops_main(RA, stack);
		stack->j++;
	}
	stack->j = 0;
	while (stack->j < 50000)
	{
		if ((stack->a[0] > stack->a[1] && stack->a[0] != stack->max)
		&& (stack->b[0] < stack->b[1] && stack->b[0] != stack->min))
		{
			ft_ops_main(SS, stack);
			flag = 0;
		}
		else if (stack->a[0] > stack->a[1] && stack->a[0] != stack->max) // Largest value of 'a' (max of bigger half)
		{	
			ft_ops_main(SA, stack);
			flag = 0;
		}
		else if (stack->b[0] < stack->b[1] && stack->b[0] != stack->min) // Smallest value of 'b' (min of smaller half)
		{
			ft_ops_main(SB, stack);
			flag = 0;
		}
		ft_ops_main(RRR, stack);
		stack->j++;
		flag++;
		if (flag > (size_t)stack->median)
			break ;
	}
	while (stack->b[0] != stack->median && stack->a[0] != stack->median + 1)
	{
		if ((stack->b[0] != stack->median) && stack->median + 1)
			ft_ops_main(RR, stack);
		else if (stack->b[0] != stack->median) // Largest value of 'b' (max of smaller half)
			ft_ops_main(RB, stack);
		else if (stack->a[0] != stack->median + 1) // Smalles value of 'a' (min of bigger half)
			ft_ops_main(RA, stack);
	}
		while (stack->size_b != 0)
			ft_ops_main(PA, stack);
}
