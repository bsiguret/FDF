/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 03:50:14 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/08 03:50:17 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t size;
	size_t j;

	size = ft_strlen(needle);
	if (size == 0)
		return ((char*)haystack);
	i = 0;
	j = 0;
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j] && len > i + j)
		{
			if (j == size - 1)
				return ((char*)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
