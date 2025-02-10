/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:32:12 by fhoshina          #+#    #+#             */
/*   Updated: 2024/10/31 22:13:57 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

static void	display(long nl, int fd)
{
	if (nl == 0)
		return ;
	else
	{
		display(nl / 10, fd);
		ft_putchar_fd((nl % 10) + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nl;

	nl = (long)n;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (nl < 0)
	{
		ft_putchar_fd('-', fd);
		nl = -nl;
	}
	display(nl, fd);
}
