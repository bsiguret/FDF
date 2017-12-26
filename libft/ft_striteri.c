/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:42:17 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/09 06:20:08 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;
	int	j;

	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s);
		j = 0;
		while (j < i)
		{
			f(j, s);
			j++;
			s++;
		}
	}
}
