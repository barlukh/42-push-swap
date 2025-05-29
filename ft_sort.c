/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:49:14 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/29 18:13:15 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

static void	ft_ops_main(int operation, t_stacks *stack);

void	ft_sort(t_stacks *stack)
{
	size_t	flag;

	flag = 0;
	stack->j = 0;
	stack->pivot = stack->size_a / 2;
	while (stack->j < stack->pivot)
	{
		ft_ops_main(PB, stack);
		stack->j++;
	}
	stack->j = 0;
	while (stack->j < 1000)
	{
		// if (stack->a[0] > stack->a[1] && stack->b[0] < stack->b[1])
		// {
		// 	ft_ops_main(SS, stack);
		// 	flag = 0;
		// }
		if (stack->a[0] > stack->a[1] && stack->a[0] != 9) // Hardcoded largest value of stack 'a'
		{	
			ft_ops_main(SA, stack);
			flag = 0;
		}
		else if (stack->b[0] < stack->b[1] && stack->b[0] != 1) // Hardcoded smallest value of stack 'b'
		{
			ft_ops_main(SB, stack);
			flag = 0;
		}
		ft_ops_main(RRR, stack);
		stack->j++;
		flag++;
		if (flag > stack->pivot)
			break ;
	}
	while (stack->b[0] != 4) // Hardcoded largest values of stack 'b'
		ft_ops_main(RB, stack);
	while (stack->size_b != 0)
			ft_ops_main(PA, stack);
}

// Calls relevant function based on the operation passed
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
