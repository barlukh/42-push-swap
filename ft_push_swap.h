/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:53:58 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/26 07:24:17 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define ERROR 0

typedef struct s_struct
{
	int	*a;
}	t_struct;

/** Converts a string to an integer
 * @param s String to be converted
 * @return Converted string as a long long (integer type)
 */
long long	ft_atoi(const char *s);

/** Checks if passed arguments are valid integers
 * @param argc Argument count
 * @param argv Argument vector
 * @param stack Struct containing stacks
 * @return 1 on SUCCESS, 0 on ERROR
 */
int			ft_check_arguments(int argc, char **argv, t_struct *stack);

/** Checks if there are no duplicates in the passed stack
 * @param argc Argument count
 * @param stack Struct containing stacks
 * @return 1 on SUCCESS, 0 on ERROR
 */
int			ft_check_duplicates(int argc, t_struct *stack);

/** Checks if a character is a digit
 * @param c Character to check, passed as an int
 * @return 1 on TRUE, 0 on FALSE
 */
int			ft_isdigit(int c);

#endif
