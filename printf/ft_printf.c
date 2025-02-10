/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:23:01 by fhoshina          #+#    #+#             */
/*   Updated: 2024/11/05 16:30:55 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format(format[i], args);
		}
		else
			count += ft_write_char(format[i]);
		i++;
	}
	va_end(args);
	if (count < 0)
		return (-1);
	return (count);
}

// void	check_return_value(int a, int b)
// {
// 	if (a == b)
// 		write(1, "OK\n", 3);
// 	else
// 		write(1, "KO\n", 3);
// }
// int	main(void)
// {
// 	int a, b;
// 	a = printf("%p %p\n", LONG_MIN, LONG_MAX);
// 	b = ft_printf("%p %p\n", LONG_MIN, LONG_MAX);
// 	check_return_value(a, b);
// 	a = printf("%p %p\n", -ULONG_MAX, -ULONG_MAX);
// 	b = ft_printf("%p %p\n", -ULONG_MAX, -ULONG_MAX);
// 	check_return_value(a, b);
// 	a = printf("%p %p\n", 0, 0);
// 	b = ft_printf("%p %p\n", 0, 0);
// 	check_return_value(a, b);
// 	a = printf("");
// 	b = ft_printf("");
// 	check_return_value(a, b);
// 	a = printf(NULL);
// 	b = ft_printf(NULL);
// 	check_return_value(a, b);
// }