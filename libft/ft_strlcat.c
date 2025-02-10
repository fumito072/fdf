/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:29:32 by fhoshina          #+#    #+#             */
/*   Updated: 2024/11/05 20:48:05 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	max_copy;
	size_t	d;
	size_t	s;
	char	*ss;

	ss = (char *)src;
	d = ft_strlen(dest);
	s = ft_strlen(ss);
	if (size <= d)
		return (size + s);
	max_copy = size - d - 1;
	if (max_copy > s)
		ft_memcpy(dest + d, src, s + 1);
	else
	{
		ft_memcpy(dest + d, src, max_copy);
		dest[d + max_copy] = '\0';
	}
	return (s + d);
}

// int main(void)
// {
// 	char	dest[30] = "Hello, ";
// 	const char	src[] = "world!";
// 	size_t	len;
// 	len = ft_strlcat(dest, src, 30);
// 	printf("After strlcat, dest: %s\n", dest);
// 	printf("Returned length: %zu\n\n", len);
// 	strcpy(dest, "Hello, ");
// 	len = ft_strlcat(dest, src, 10);
// 	printf("After strlcat (size 10), dest: %s\n", dest);
// 	printf("Returned length: %zu\n\n", len);
// 	strcpy(dest, "Hello, ");
// 	len = ft_strlcat(dest, src, 5);
// 	printf("After strlcat (size 5), dest: %s\n", dest);
// 	printf("Returned length: %zu\n\n", len);
// 	return 0;
// }