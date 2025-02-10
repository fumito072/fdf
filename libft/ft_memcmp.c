/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:37:52 by fhoshina          #+#    #+#             */
/*   Updated: 2024/10/29 14:59:58 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ms1;
	unsigned char	*ms2;

	ms1 = (unsigned char *)s1;
	ms2 = (unsigned char *)s2;
	while (n != 0)
	{
		if (*ms1 != *ms2)
			return (*ms1 - *ms2);
		ms1++;
		ms2++;
		n--;
	}
	if (n != 0)
		return (*ms1 - *ms2);
	return (0);
}
