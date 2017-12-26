/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 22:42:53 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/08 02:11:22 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int size;
	int j;

	size = ft_strlen(needle);
	if (size == 0)
		return ((char*)haystack);
	i = 0;
	j = 0;
	while (haystack[i] != '\0')
	{
		while (haystack[i + j] == needle[j])
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
