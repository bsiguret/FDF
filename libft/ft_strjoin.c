/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 02:22:46 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/09 02:32:50 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (s1 != NULL && s2 != NULL)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		i = 0;
		if ((str = ft_memalloc(len + 1)) == NULL)
			return (NULL);
		while (*s1)
		{
			str[i] = *s1++;
			++i;
		}
		while (*s2)
		{
			str[i] = *s2++;
			++i;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
