/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:24:01 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/24 12:24:10 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

# define BASE10 10
# define BASE16 16
# define DECIMAL "0123456789"
# define HEX_LCASE "0123456789abcdef"
# define HEX_UCASE "0123456789ABCDEF"

/** Writes a string with format specifiers into the standard output
 * @param s String to write
 * @param ... Additional variadic arguments matching format specifiers
 * @return Number of characters written, -1 on error
 */
int	ft_printf(const char *s, ...);

/** Writes a charater into the standard output
 * @param c Character to write
 * @return Number of characters written, -1 on error
 */
int	ft_putchar_m(int c);

/** Writes a memory address of a pointer into the standard output
 * @param p Memory address to write (represented as an integer)
 * @return Number of characters written, -1 on error
 */
int	ft_putnbr_p(uintptr_t p);

/** Writes a signed integer into the standard output
 * @param n Integer to write
 * @return Number of characters written, -1 on error
 */
int	ft_putnbr_s(int n);

/** Writes an unsigned integer into the standard output
 * @param n Integer to write
 * @param base Base of the integer
 * @param style Style format indicator for hexadecimal letters
 * @return Number of characters written, -1 on error
 */
int	ft_putnbr_u(unsigned int n, unsigned int base, const char *style);

/** Writes a string into the standard output
 * @param s String to write
 * @return Number of characters written, -1 on error
 */
int	ft_putstr_m(const char *s);

#endif
