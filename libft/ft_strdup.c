/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:04:39 by fhoshina          #+#    #+#             */
/*   Updated: 2024/10/24 16:54:50 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;
	int		size;
	char	*sub;

	sub = (char *)s;
	size = ft_strlen(sub) + 1;
	new = malloc(sizeof(char) * (size));
	if (!(new))
		return (NULL);
	i = 0;
	while (sub[i])
	{
		new[i] = sub[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
