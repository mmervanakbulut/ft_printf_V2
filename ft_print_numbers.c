/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musakbul <musakbul@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:59:54 by musakbul          #+#    #+#             */
/*   Updated: 2025/07/22 18:59:54 by musakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	num;
	int		len;

	len = 0;
	num = n;
	if (num < 0)
	{
		len += write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
		len += ft_putnbr(num / 10);
	len += write(1, &"0123456789"[num % 10], 1);
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putunbr(n / 10);
	len += write(1, &"0123456789"[n % 10], 1);
	return (len);
}

int	ft_puthex(unsigned int n, int uppercase)
{
	char	*base;
	int		len;

	if (uppercase)
	{
		base = "0123456789ABCDEF";
	}
	else
	{
		base = "0123456789abcdef";
	}
	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, uppercase);
	len += write(1, &base[n % 16], 1);
	return (len);
}
