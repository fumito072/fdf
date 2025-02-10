/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:29:10 by fhoshina          #+#    #+#             */
/*   Updated: 2024/10/24 21:49:27 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	cc;

	src = (unsigned char *)s;
	cc = (unsigned char)c;
	while (n > 0)
	{
		if (*src == cc)
			return ((unsigned char *)src);
		src++;
		n--;
	}
	return (0);
}
