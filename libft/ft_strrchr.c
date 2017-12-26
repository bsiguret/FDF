/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:01:33 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/08 22:12:19 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		n;

	n = ft_strlen(s) + 1;
	while (n--)
	{
		if (s[n] == (char)c)
		{
			s = &s[n];
			return ((char*)s);
		}
	}
	return (NULL);
}
