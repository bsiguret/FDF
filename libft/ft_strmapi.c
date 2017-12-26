/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:39:18 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/09 00:43:01 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	if (s != NULL)
	{
		if ((str = ft_memalloc(ft_strlen(s) + 1)) == NULL)
			return (NULL);
		ft_strcpy(str, s);
		while (str[i])
		{
			str[i] = f(i, str[i]);
			++i;
		}
		return (str);
	}
	return (NULL);
}
