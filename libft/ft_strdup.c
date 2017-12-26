/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:46:49 by bsiguret          #+#    #+#             */
/*   Updated: 2017/12/07 15:47:47 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	int		i;

	i = 0;
	if ((out = (char*)malloc(ft_strlen(s1) + 1)) == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
