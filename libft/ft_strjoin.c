/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:05:15 by fhoshina          #+#    #+#             */
/*   Updated: 2024/11/05 23:02:25 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;
	char	*sub1;
	char	*sub2;

	i = -1;
	j = -1;
	sub1 = (char *)s1;
	sub2 = (char *)s2;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(sub1) + ft_strlen(sub2) + 1));
	if (!(s3))
		return (NULL);
	while (s1 != NULL && s1[++j] != '\0')
		s3[++i] = s1[j];
	j = -1;
	while (s2 != NULL && s2[++j] != '\0')
		s3[++i] = s2[j];
	s3[++i] = '\0';
	return (s3);
}

#include <stdio.h>
int main()
{
	printf("%s\n", ft_strjoin("1234", "56789"));
}