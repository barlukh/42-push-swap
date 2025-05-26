/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:53:58 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/26 15:04:15 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // REMEMBER TO REMOVE BEFORE SUBMISSION!

# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define ERROR 0
# define ERRONLY 0
# define ERRFREEARG 1
# define ERRFREESTCK 2
# define ERRFREEARGSTCK 3
# define FREESTCK 4
# define FREEARGSTCK 5

typedef struct s_struct
{
	int		*a;
	size_t	size;
}	t_struct;

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
int			ft_check_arguments(char **argv, t_struct *stack);

/** Checks if there are no duplicates in the passed stack
 * @param stack Struct containing stack variables
 * @return 1 on SUCCESS, 0 on ERROR
 */
int			ft_check_duplicates(t_struct *stack);

/** Handles different error calls
 * @param error Error number
 * @param argv Argument vector
 * @param stack Struct containing stack variables
 * @return 0 (zero) 
 */
int			ft_exit(int error, char **argv, t_struct stack);

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

/** Splits a string according to a specified delimiter
 * @param s String to split
 * @param c Delimiter
 * @return Array of new strings, 'NULL' if the allocation fails
 */
char		**ft_split(char const *s, char c, t_struct *stack);

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
