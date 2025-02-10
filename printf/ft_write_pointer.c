/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:16:16 by fhoshina          #+#    #+#             */
/*   Updated: 2024/11/07 15:30:54 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_pointer(void *p)
{
	int	count;

	count = 0;
	if (p == NULL)
		return (write(1, "(nil)", 5));
	count += ft_write_str("0x");
	count += ft_write_hexadecimal((unsigned long)p, 'x');
	return (count);
}
