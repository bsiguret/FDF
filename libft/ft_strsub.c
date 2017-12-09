/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 02:02:16 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/09 02:19:47 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s != NULL)
	{
		if ((str = ft_memalloc(len + 1)) == NULL)
			return (NULL);
		while (len--)
		{
			str[i] = s[start + i];
			++i;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
