/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:51:49 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/08 22:11:31 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	size_t		n;

	n = ft_strlen(s) + 1;
	i = 0;
	while (n--)
	{
		if (s[i] == (char)c)
		{
			s = &s[i];
			return ((char*)s);
		}
		++i;
	}
	return (NULL);
}
