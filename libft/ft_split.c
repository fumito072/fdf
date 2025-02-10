/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:45:24 by fhoshina          #+#    #+#             */
/*   Updated: 2024/10/31 22:12:14 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static char	*connect_word(char const *s, size_t start, size_t end)
{
	int		i;
	size_t	len;
	size_t	last_len;
	char	*words;

	len = end - start;
	last_len = len;
	words = malloc(len + 1);
	if (!words)
		return (NULL);
	i = 0;
	while (len > 0 && *s)
	{
		words[i++] = s[start++];
		len--;
	}
	words[last_len] = '\0';
	return (words);
}

static void	end_point(char const *s, size_t *start, size_t *end, char c)
{
	while (s[*start] == c && s[*start])
		(*start)++;
	*end = *start;
	while (s[*end] != c && s[*end])
		(*end)++;
}

static void	free_func(char **lst, size_t i)
{
	while (i > 0)
	{
		free(lst[i - 1]);
		i--;
	}
	free(lst);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	i;
	size_t	start;
	size_t	end;

	lst = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	start = 0;
	end = 0;
	while (i < count_word(s, c))
	{
		end_point(s, &start, &end, c);
		lst[i] = connect_word(s, start, end);
		if (!lst[i])
		{
			free_func(lst, i);
			return (NULL);
		}
		i++;
		start = end;
	}
	lst[i] = NULL;
	return (lst);
}

// int main(void)
// {
//     char **result;
//     const char *str = "lorem ipsum dolor sit amet, consectetur mi.";
//     char c = 'i';
//     int i;

//     result = ft_split(str, c);
//     i = 0;
//     while (result[i] != NULL)
//     {
//         printf("%d: %s\n", i + 1, result[i]);
//         free(result[i]);
//         i++;
//     }

//     free(result);
//     return (0);
// }
