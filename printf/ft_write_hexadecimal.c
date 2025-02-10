/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:36:46 by fhoshina          #+#    #+#             */
/*   Updated: 2024/11/07 15:29:10 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hexadecimal(unsigned long number, char format)
{
	char	*base;

	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (ft_base(number, base));
}

int	ft_base(unsigned long number, char *base)
{
	int	count;

	count = 0;
	if (number > 15)
	{
		count += ft_base(number / 16, base);
		count += ft_base(number % 16, base);
	}
	else
		count += ft_write_char(base[number]);
	if (count < 0)
		return (-1);
	return (count);
}
