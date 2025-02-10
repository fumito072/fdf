/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:29:59 by fhoshina          #+#    #+#             */
/*   Updated: 2024/11/07 15:31:07 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_str(char *format)
{
	int	count;

	count = 0;
	if (format == NULL)
		return (write(1, "(null)", 6));
	while (format[count])
	{
		write(1, &format[count], 1);
		count++;
	}
	if (count < 0)
		return (-1);
	return (count);
}
