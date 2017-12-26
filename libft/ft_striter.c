/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:42:17 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/09 06:17:51 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int i;
	int	j;

	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s);
		j = 0;
		while (j < i)
		{
			f(s);
			s++;
			j++;
		}
	}
}
