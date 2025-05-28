/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:53:58 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/28 09:46:28 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONFIG_H
# define FT_CONFIG_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // REMEMBER TO REMOVE BEFORE SUBMISSION!

# define TRUE 1
# define FALSE 0
# define ERROR 1
# define SUCCESS 0

# define ERR_MSG 1
# define ERRFREE_ARG 2
# define ERRFREE_A 3
# define ERRFREE_AB 4
# define ERRFREE_ARG_A 5
# define ERRFREE_ARG_AB 6
# define FREE_AB 7
# define FREE_ARG_AB 8

typedef struct s_args
{
	int		argc;
	char	**argv;
	int		offset;
}	t_args;

typedef struct s_stacks
{
	int		*a;
	int		*b;
	size_t	size;
}	t_stacks;

/** Converts a string to an integer
 * @param s String to be converted
 * @return Converted string as a long long (integer type)
 */
long long	ft_atoi(const char *s);

/** Checks if passed arguments are valid integers
 * @param argv Argument vector
 * @param stack Struct containing stack variables
 * @return 1 on SUCCESS, 0 on ERROR
 */
int			ft_check_arguments(char **argv, t_stacks *stack);

/** Checks if there are no duplicates in the passed stack
 * @param stack Struct containing stack variables
 * @return 1 on SUCCESS, 0 on ERROR
 */
int			ft_check_duplicates(t_stacks *stack);

/** Handles different error calls
 * @param error Error type
 * @param argv Argument vector
 * @param stack Struct containing stack variables
 * @return 0 (zero)
 */
int			ft_end(int error, char **argv, t_stacks *stack);

/** Checks if a character is a digit
 * @param c Character to check, passed as an int
 * @return 1 on TRUE, 0 on FALSE
 */
int			ft_isdigit(int c);

/** Copies bytes from one memory area to another; the areas must not overlap
 * @param dest Pointer to the destination memory area
 * @param src Pointer to the source memory area
 * @param n Number of bytes to copy
 * @return Pointer to the destination memory area
 */
void		*ft_memcpy(void *dest, const void *src, size_t n);

/** Parses command line arguments checking for invalid input
 * @param arg Struct containing argument variables
 * @param stack Struct containing stack variables
 * @return 1 on SUCCESS, 0 on ERROR
 */
int			ft_parse_input(t_args *arg, t_stacks *stack);

/** Splits a string according to a specified delimiter
 * @param s String to split
 * @param c Delimiter
 * @param stack Struct containing stack variables
 * @return Array of new strings, 'NULL' if the allocation fails
 */
char		**ft_split(char const *s, char c, t_stacks *stack);

/** Scans a string for the first instance of 'c'
 * @param s String to search
 * @param c Character to search for, passed as an int
 * @return Pointer to the matching location, 'NULL' if no match
 */
char		*ft_strchr(const char *s, int c);

/** Duplicates a string using dynamic memory allocation
 * @param s String to duplicate
 * @return Pointer to the duplicated string, 'NULL' if the allocation fails
 */
char		*ft_strdup(const char *s);

/** Calculates the length of a string
 * @param s String to calculate the length of
 * @return Number of bytes in the passed string
 */
size_t		ft_strlen(const char *s);

/** Creates a substring using dynamic memory allocation
 * @param s String to make the substring from
 * @param start Starting index
 * @param len Length of the substring
 * @return Pointer to the new substring, 'NULL' if the allocation fails
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
