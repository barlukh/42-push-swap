/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:43:55 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/26 07:51:57 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long long	ft_atoi(const char *s)
{
	int			sign;
	long long	n;
	size_t		i;	

	sign = 1;
	n = 0;
	i = 0;
	if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (s[i] != '\0')
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	n = n * sign;
	return (n);
}

int	ft_check_arguments(char **argv, t_struct *stack)
{
	size_t		i;
	size_t		j;
	long long	n;

	i = 1;
	while (i <= stack->size)
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
		stack->a[i - 1] = (int)n;
		i++;
	}
	return (SUCCESS);
}

int	ft_check_duplicates(t_struct *stack)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->a[i] == stack->a[j])
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}
