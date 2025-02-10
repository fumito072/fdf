/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:16:52 by fhoshina          #+#    #+#             */
/*   Updated: 2024/10/29 18:03:05 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_size(int n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
		cnt++;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static char	*roop(int n, char *num)
{
	num--;
	while (n != 0)
	{
		*num = '0' + (n % 10);
		n /= 10;
		num--;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_size(n);
	number = (char *)malloc(sizeof(char) * len + 1);
	if (!number)
		return (NULL);
	if (n > 0 && number)
	{
		number = roop(n, number + len);
		number += 1;
	}
	else
	{
		n *= -1;
		number = roop(n, number + len);
		*number = '-';
	}
	number[len] = '\0';
	return (number);
}

// int	main(void)
// {
// 	char *str;
// 	str = ft_itoa(192843);
// 	printf("%s", str);
// 	free(str);
// 	str = ft_itoa(0);
// 	printf("%s", str);
// 	free(str);
// 	str = ft_itoa(2147483647);
// 	printf("%s", str);
// 	free(str);
// 	str = ft_itoa(-2147483648);
// 	printf("%s", str);
// 	free(str);
// }