/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 06:13:44 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/08 03:56:57 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const char	*strsrc;
	char		*strdest;
	size_t		i;

	strsrc = (char*)src;
	strdest = (char*)dest;
	i = 0;
	while (i < n)
	{
		strdest[i] = strsrc[i];
		if (strdest[i] == c)
			return (&strdest[i + 1]);
		++i;
	}
	return (NULL);
}
