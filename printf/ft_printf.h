/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:12:29 by fhoshina          #+#    #+#             */
/*   Updated: 2025/02/07 03:50:25 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_format(const char format, va_list args);
int	ft_write_char(char c);
int	ft_write_hexadecimal(unsigned long number, char format);
int	ft_base(unsigned long number, char *base);
int	ft_write_num(int number);
int	ft_write_pointer(void *p);
int	ft_write_str(char *format);
int	ft_write_unsigned(unsigned int number);

#endif