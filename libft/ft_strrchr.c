/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:18:30 by fhoshina          #+#    #+#             */
/*   Updated: 2024/10/25 23:35:44 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	cast;
	char	*sub;

	p = NULL;
	cast = (char)c;
	sub = (char *)s;
	while (*sub)
	{
		if (*sub == cast)
			p = sub;
		sub++;
	}
	if (c == '\0')
		return (sub);
	return (p);
}
