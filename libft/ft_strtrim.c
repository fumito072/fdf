/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:15:23 by fhoshina          #+#    #+#             */
/*   Updated: 2024/10/31 22:15:43 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*triming(char *trim, char const *s1, size_t start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	int		len;
	char	*se;
	char	*trim;

	len = ft_strlen((char *)s1);
	se = (char *)set;
	start = 0;
	while (s1[start] && ft_strchr(se, s1[start]))
		start++;
	end = len;
	while (end > start && ft_strchr(se, s1[end - 1]))
		end--;
	trim = (char *)malloc(end - start + 1);
	if (!trim)
		return (NULL);
	if (start > end)
		return (NULL);
	trim = triming(trim, s1, start, end - start);
	return (trim);
}
