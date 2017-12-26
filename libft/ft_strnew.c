/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:24:35 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/08 23:36:26 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *str;

	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	return (ft_memset(str, 0, size + 1));
}
