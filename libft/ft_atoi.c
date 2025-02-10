/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:28:58 by fhoshina          #+#    #+#             */
/*   Updated: 2024/11/05 15:52:24 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static long long	max_display(const char *c)
{
	long long	res;

	res = 0;
	while ('0' <= *c && *c <= '9')
	{
		if (res > (LLONG_MAX - (*c - '0')) / 10)
			return (LLONG_MAX);
		res = res * 10 + (*c - '0');
		c++;
	}
	return (res);
}

static long long	min_display(const char *c)
{
	long long	res;

	res = 0;
	while ('0' <= *c && *c <= '9')
	{
		if (-1 * res < (LLONG_MIN + (*c - '0')) / 10)
			return (LLONG_MIN);
		res = res * 10 + (*c - '0');
		c++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int	flag;
	int	flag2;

	flag = 0;
	flag2 = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
	{
		str++;
	}
	while (*str == '+' || *str == '-')
	{
		flag2++;
		if (*str == '-')
			flag = 1;
		str++;
	}
	if (flag == 1 && flag2 < 2)
		return ((int)(-1 * min_display(str)));
	if (flag2 == 1 || flag2 == 0)
		return ((int)max_display(str));
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	printf("%d\n", atoi("9223372036854775808"));
// 	printf("%d\n", ft_atoi("9223372036854775808"));
// 	printf("%d\n", atoi("-9223372036854775809"));
// 	printf("%d\n", ft_atoi("-9223372036854775809"));
// 	printf("%d\n", atoi("9223372036854775807"));
// 	printf("%d\n", ft_atoi("9223372036854775807"));
// 	printf("%d\n", atoi("-9223372036854775808"));
// 	printf("%d\n", ft_atoi("-9223372036854775808"));
// }
