/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:29:26 by fhoshina          #+#    #+#             */
/*   Updated: 2024/10/30 19:26:34 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	f_copy(unsigned char *d, unsigned char *s, size_t count)
{
	while (count)
	{
		*d++ = *s++;
		count--;
	}
}

static void	b_copy(unsigned char *d, unsigned char *s, size_t count)
{
	while (count)
	{
		*d-- = *s--;
		count--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s)
	{
		d += count - 1;
		s += count - 1;
		b_copy(d, s, count);
	}
	else
	{
		f_copy(d, s, count);
	}
	return (dest);
}

// int main(void)
// {
//     char	src[] = "lorem ipsum dolor sit amet";
// 	char	*dest;
//     ft_memmove("consectetur",src, 3);
//     printf("%s\n", dest);
//     return 0;
// }
