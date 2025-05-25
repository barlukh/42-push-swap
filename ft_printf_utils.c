/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgazur <bgazur@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:04:20 by bgazur            #+#    #+#             */
/*   Updated: 2025/05/25 16:56:46 by bgazur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_putchar_m(int c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr_p(uintptr_t p)
{
	int	count;
	int	check;

	if (p == 0)
		return (ft_putstr_m("(nil)"));
	count = 0;
	if (p < BASE16)
	{
		check = ft_putstr_m("0x");
		if (check == -1)
			return (-1);
		count += check;
	}
	if (p >= BASE16)
	{
		check = ft_putnbr_p(p / BASE16);
		if (check == -1)
			return (-1);
		count += check;
	}
	if (ft_putchar_m(HEX_LCASE[p % BASE16]) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_putnbr_s(int n)
{
	int	count;
	int	check;

	if (n == INT_MIN)
		return (ft_putstr_m("-2147483648"));
	count = 0;
	if (n < 0)
	{
		if (ft_putchar_m('-') == -1)
			return (-1);
		count++;
		n = -n;
	}
	if (n >= BASE10)
	{
		check = ft_putnbr_s(n / BASE10);
		if (check == -1)
			return (-1);
		count += check;
	}
	if (ft_putchar_m(DECIMAL[n % BASE10]) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_putnbr_u(unsigned int n, unsigned int base, const char *set)
{
	int	count;
	int	check;

	count = 0;
	if (n >= base)
	{
		check = ft_putnbr_u(n / base, base, set);
		if (check == -1)
			return (-1);
		count += check;
	}
	if (ft_putchar_m(set[n % base]) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_putstr_m(const char *s)
{
	int	count;

	if (!s)
		s = "(null)";
	count = 0;
	while (s[count] != '\0')
	{
		if (ft_putchar_m(s[count]) == -1)
			return (-1);
		count++;
	}
	return (count);
}
