/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 04:00:32 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/08 20:53:03 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*strsrc;
	char	*strdst;

	strsrc = (char*)src;
	strdst = (char*)dst;
	if (strsrc == strdst)
		return (dst);
	if (strsrc < strdst)
	{
		strsrc = &strsrc[len - 1];
		strdst = &strdst[len - 1];
		while (len--)
			*strdst-- = *strsrc--;
	}
	else
	{
		while (len--)
			*strdst++ = *strsrc++;
	}
	return (dst);
}
