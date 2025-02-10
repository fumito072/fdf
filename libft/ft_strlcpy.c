/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:29:36 by fhoshina          #+#    #+#             */
/*   Updated: 2024/11/05 20:47:05 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i])
	{
		i++;
	}
	if (size == 0)
	{
		return (i);
	}
	j = 0;
	while (j < (size - 1) && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

// int main(void)
// {
// 	char	src[] = "Hello, world!";
// 	char	dst[20];
// 	size_t	len;

// 	len = ft_strlcpy(dst, src, 20);
// 	printf("src: %s\n", src);
// 	printf("dst: %s\n", dst);
// 	printf("Returned length: %zu\n\n", len);

// 	len = ft_strlcpy(dst, src, 0);
// 	printf("src: %s\n", src);
// 	printf("dst (size 0): %s\n", dst);
// 	printf("Returned length: %zu\n\n", len);

// 	return 0;
// }