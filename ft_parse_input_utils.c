/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:43:55 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/29 09:23:57 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_config.h"

static long long	ft_atoi(const char *s);
static int			ft_check_duplicates(t_stacks *stack);
static int			ft_isdigit(int c);

int	ft_check_arguments(char **argv, t_stacks *stack)
{
	size_t		i;
	size_t		j;
	long long	n;

	i = 0;
	while (i < stack->size_a)
	{
		if (argv[i] == NULL || argv[i][0] == '\0')
			return (ERROR);
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]) && !(argv[i][j] == '-' && j == 0))
				return (ERROR);
			j++;
		}
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (ERROR);
		stack->a[i] = (int)n;
		i++;
	}
	if (ft_check_duplicates(stack) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	ft_end(int end_flag, char **argv, t_stacks *stack)
{
	size_t	i;

	i = 0;
	if (end_flag == FREE_ARG_AB || end_flag == ERRFREE_ARG
		|| end_flag == ERRFREE_ARG_A || end_flag == ERRFREE_ARG_AB)
	{
		while (argv[i] != NULL)
			free(argv[i++]);
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
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stack->size_a)
	{
		j = i + 1;
		while (j < stack->size_a)
		{
			if (stack->a[i] == stack->a[j])
				return (ERROR);
			j++;
		}
		i++;
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
