/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:24:20 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/25 14:40:39 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "ft_printf.h"

/** Converts a string to an integer
 * @param nptr String to be converted
 * @return Converted string as an int, '0' on error
 */
int	ft_atoi(const char *nptr);

/** Checks if a character is a digit
 * @param c Character to check, passed as an int
 * @return 1 on True, 0 on False
 */
int	ft_isdigit(int c);

#endif
