/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:54:03 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/08 21:14:13 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*strs;
	int		i;

	strs = (char*)s;
	i = 0;
	while (n--)
	{
		if (strs[i] == (char)c)
		{
			strs = &strs[i];
			return (strs);
		}
		++i;
	}
	return (NULL);
}
