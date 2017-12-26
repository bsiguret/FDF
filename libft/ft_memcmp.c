/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:33:13 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/08 21:47:44 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *strs1;
	unsigned char *strs2;

	strs1 = (unsigned char*)s1;
	strs2 = (unsigned char*)s2;
	while (n--)
	{
		if (*strs1 != *strs2)
			return (*strs1 - *strs2);
		strs1++;
		strs2++;
	}
	return (0);
}
