/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musakbul <musakbul@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:16:25 by musakbul          #+#    #+#             */
/*   Updated: 2025/07/24 19:41:37 by musakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(unsigned long n)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		len += ft_putptr(n / 16);
	len += write(1, &base[n % 16], 1);
	return (len);
}

int	ft_print_pointer(void *ptr)
{
	int	len;

	if (!ptr)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	len += ft_putptr((unsigned long)ptr);
	return (len);
}
