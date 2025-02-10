/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:41:45 by fhoshina          #+#    #+#             */
/*   Updated: 2024/11/07 23:57:50 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_num(int number)
{
	int	count;

	count = 0;
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		count += 11;
	}
	else if (number < 0)
	{
		count += ft_write_char('-');
		count += ft_write_num(-number);
	}
	else if (number > 9)
	{
		count += ft_write_num(number / 10);
		count += ft_write_num(number % 10);
	}
	else
		count += ft_write_char(number + '0');
	if (count < 0)
		return (-1);
	return (count);
}
