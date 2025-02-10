/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:05:43 by fhoshina          #+#    #+#             */
/*   Updated: 2025/02/07 03:50:54 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_unsigned(unsigned int number)
{
	int	count;

	count = 0;
	if (number > 9)
	{
		count += ft_write_num(number / 10);
		count += ft_write_num(number % 10);
	}
	else if (0 < number && number < 10)
		count += ft_write_char(number + '0');
	if (count < 0)
		return (-1);
	return (count);
}
