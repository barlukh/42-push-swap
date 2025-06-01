/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:43:55 by bgazur            #+#    #+#             */
/*   Updated: 2025/06/01 12:25:26 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

static long long	ft_atoi(const char *s);
static int			ft_check_duplicates(t_stacks *stack);
static int			ft_isdigit(int c);

int	ft_check_arguments(char **argv, t_stacks *stack)
{
	long long	n;

	stack->i = 0;
	while (stack->i < stack->size_a)
	{
		if (argv[stack->i] == NULL || argv[stack->i][0] == '\0')
			return (ERROR);
		stack->j = 0;
		while (argv[stack->i][stack->j] != '\0')
		{
			if (!ft_isdigit(argv[stack->i][stack->j])
				&& !(argv[stack->i][stack->j] == '-' && stack->j == 0))
				return (ERROR);
			stack->j++;
		}
		n = ft_atoi(argv[stack->i]);
		if (n > INT_MAX || n < INT_MIN)
			return (ERROR);
		stack->a[stack->i] = (int)n;
		stack->i++;
	}
	if (ft_check_duplicates(stack) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	ft_end(int end_flag, char **argv, t_stacks *stack)
{
	stack->i = 0;
	if (end_flag == FREE_ARG_AB || end_flag == ERRFREE_ARG
		|| end_flag == ERRFREE_ARG_A || end_flag == ERRFREE_ARG_AB)
	{
		while (argv[stack->i] != NULL)
			free(argv[stack->i++]);
		free(argv);
	}
	if (end_flag == ERRFREE_A || end_flag == ERRFREE_ARG_A)
		free(stack->a);
	if (end_flag == FREE_AB || end_flag == FREE_ARG_AB
		|| end_flag == ERRFREE_AB || end_flag == ERRFREE_ARG_AB)
	{
		free(stack->a);
		free(stack->b);
	}
	if (end_flag != FREE_AB && end_flag != FREE_ARG_AB)
	{
		write(2, "Error\n", 6);
		return (ERROR);
	}
	return (SUCCESS);
}

// Converts a string to an integer
static long long	ft_atoi(const char *s)
{
	size_t		i;
	int			sign;
	long long	n;

	i = 0;
	sign = 1;
	if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	n = 0;
	while (s[i] != '\0')
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	n = n * sign;
	return (n);
}

// Checks if there are no duplicates in the passed stack
static int	ft_check_duplicates(t_stacks *stack)
{
	stack->i = 0;
	stack->j = 0;
	while (stack->i < stack->size_a)
	{
		stack->j = stack->i + 1;
		while (stack->j < stack->size_a)
		{
			if (stack->a[stack->i] == stack->a[stack->j])
				return (ERROR);
			stack->j++;
		}
		stack->i++;
	}
	return (SUCCESS);
}

// Checks if a character is a digit
static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}
