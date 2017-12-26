/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 06:08:23 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/08 00:04:58 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*strsrc;
	char		*strdest;

	strsrc = (char*)src;
	strdest = (char*)dest;
	while (n--)
		*strdest++ = *strsrc++;
	return (dest);
}
