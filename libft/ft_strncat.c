/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:30:03 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/08 01:52:44 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dest);
	i = 0;
	while (i < n && src[i])
	{
		dest[len] = src[i++];
		++len;
	}
	dest[len] = '\0';
	return (dest);
}
