/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 02:34:55 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/09 05:54:19 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	int				end;

	if (!s)
		return (NULL);
	start = 0;
	end = (int)ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == '\n' ||
				s[start] == '\t') && s[start])
		start++;
	while ((s[end] == ' ' || s[end] == '\n' ||
				s[end] == '\t') && end > (int)start)
		end--;
	return (ft_strsub(s, start, (end - start + 1)));
}
