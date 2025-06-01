/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_config.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:53:58 by bgazur            #+#    #+#             */
/*   Updated: 2025/06/01 09:53:37 by bgazur           ###   ########.fr       */
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

# define RRR 1
# define RR 2
# define SS 3
# define PA 4
# define PB 5
# define RRA 6
# define RRB 7
# define RA 8
# define RB 9
# define SA 10
# define SB 11

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
	int		cost_a;
	int		cost_b;
	int		cost_total;
	int		dir_a;
	int		dir_b;
	int		locked_a;
	int		locked_b;
	int		max;
	int		temp;
	float	mean;
	size_t	i;
	size_t	j;
	size_t	size_a;
	size_t	size_b;
}	t_stacks;

/** Checks if passed arguments are valid integers
 * @param argv Argument vector
 * @param stack Struct containing stack variables
 * @return 1 on SUCCESS, 0 on ERROR
 */
int		ft_check_arguments(char **argv, t_stacks *stack);

/** Compares different costs of movement and sets the correct direction
 * @param stack Struct containing stack variables
 * @return None
 */
void	ft_cost_dir(t_stacks *stack);

/** Handles different error calls
 * @param end_flag Flag type
 * @param argv Argument vector
 * @param stack Struct containing stack variables
 * @return '0' zero
 */
int		ft_end(int end_flag, char **argv, t_stacks *stack);

/** Checks if an array of numbers is sorted in an ascending order
 * @param stack Struct containing stack variables
 * @return 1 on TRUE, 0 on FALSE
 */
int		ft_is_sorted(t_stacks *stack);

/** Finds the max value in an array of numbers
 * @param stack Struct containing stack variables
 * @return None
 */
void	ft_max(t_stacks *stack);

/** Finds the mean of an array of numbers
 * @param stack Struct containing stack variables
 * @return None
 */
void	ft_mean(t_stacks *stack);

/** Copies bytes from one memory area to another; the areas must not overlap
 * @param dest Pointer to the destination memory area
 * @param src Pointer to the source memory area
 * @param n Number of bytes to copy
 * @return Pointer to the destination memory area
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/** Calls relevant operation based on the argument passed
 * @param operation Expands to the relevant operation
 * @param stack Struct containing stack variables
 * @return None
 */
void	ft_ops_main(int operation, t_stacks *stack);

/** Shifts down all elements of stack 'a' and 'b' by 1
 * @param stack Struct containing stack variables
 * @return None
 */
void	ft_ops_multiple_reverse(t_stacks *stack);

/** Shifts down up elements of stack 'a' and 'b' by 1
 * @param stack Struct containing stack variables
 * @return None
 */
void	ft_ops_multiple_rotate(t_stacks *stack);

/** Swaps the first 2 elements at the top of stack 'a' and stack 'b'
 * @param stack Struct containing stack variables
 * @return None
 */
void	ft_ops_multiple_swap(t_stacks *stack);

/** Take the first element at the top of 'b' and put it at the top of 'a'
 * @param stack Struct containing stack variables
 * @return None
 */
void	ft_ops_single_push_a(t_stacks *stack);

/** Take the first element at the top of 'a' and put it at the top of 'b'
 * @param stack Struct containing stack variables
 * @return None
 */
void	ft_ops_single_push_b(t_stacks *stack);

/** Shifts down all elements of stack 'a' or 'b' by 1
 * @param operation Expands to the relevant operation
 * @param stack Struct containing stack variables
 * @return None
 */
void	ft_ops_single_reverse(int operation, t_stacks *stack);

/** Shifts up all elements of stack 'a' or 'b' by 1
 * @param operation Expands to the relevant operation
 * @param stack Struct containing stack variables
 * @return None
 */
void	ft_ops_single_rotate(int operation, t_stacks *stack);

/** Swaps the first 2 elements at the top of stack 'a' or stack 'b'
 * @param operation Expands to the relevant operation
 * @param stack Struct containing stack variables
 * @return None
 */
void	ft_ops_single_swap(int operation, t_stacks *stack);

/** Parses command line arguments checking for invalid input
 * @param arg Struct containing argument variables
 * @param stack Struct containing stack variables
 * @return 1 on SUCCESS, 0 on ERROR
 */
int		ft_parse_input(t_args *arg, t_stacks *stack);

/** Sorts a stack of integers in an ascending order
 * @param stack Struct containing stack variables
 * @return None
 */
void	ft_sort(t_stacks *stack);

/** Splits a string according to a specified delimiter
 * @param s String to split
 * @param c Delimiter
 * @param stack Struct containing stack variables
 * @return Array of new strings, 'NULL' if the allocation fails
 */
char	**ft_split(char const *s, char c, t_stacks *stack);

/** Scans a string for the first instance of 'c'
 * @param s String to search
 * @param c Character to search for, passed as an int
 * @return Pointer to the matching location, 'NULL' if no match
 */
char	*ft_strchr(const char *s, int c);

/** Calculates the length of a string
 * @param s String to calculate the length of
 * @return Number of bytes in the passed string
 */
size_t	ft_strlen(const char *s);

/** Creates a substring using dynamic memory allocation
 * @param s String to make the substring from
 * @param start Starting index
 * @param len Length of the substring
 * @return Pointer to the new substring, 'NULL' if the allocation fails
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
