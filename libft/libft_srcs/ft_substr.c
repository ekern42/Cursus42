/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekern <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:26:43 by ekern             #+#    #+#             */
/*   Updated: 2021/10/15 13:08:17 by ekern            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *src, unsigned int start, size_t n)
{
	char	*dest;
	size_t	a;

	if (src == NULL)
		return (NULL);
	a = ft_strlen(src);
	if (a < start)
		a = 0;
	else
		a -= start;
	if (n > a)
		n = a;
	a = 0;
	dest = malloc(sizeof(char) * n + 1);
	if (dest == NULL)
		return (NULL);
	while (a < n)
	{
		dest[a] = src[start];
		a++;
		start++;
	}
	dest[a] = '\0';
	return (dest);
}
