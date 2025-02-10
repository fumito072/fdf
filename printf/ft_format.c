/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:29:09 by fhoshina          #+#    #+#             */
/*   Updated: 2025/02/07 03:50:38 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_write_char((char)va_arg(args, int));
	if (format == 's')
		count += ft_write_str(va_arg(args, char *));
	if (format == 'p')
		count += ft_write_pointer(va_arg(args, void *));
	if (format == 'd' || format == 'i')
		count += ft_write_num(va_arg(args, int));
	if (format == 'u')
		count += ft_write_unsigned(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		count += ft_write_hexadecimal(va_arg(args, unsigned int), format);
	if (format == '%')
		count += write(1, "%", 1);
	return (count);
}
