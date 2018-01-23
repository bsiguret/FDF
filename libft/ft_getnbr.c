/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:50:25 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/23 16:39:09 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_getnbr(int size, char *str)
{
	char			**ret;
	int				*nbr;
	int				count;

	count = 0;
	ret = ft_strsplit(str, ' ');
	nbr = (int*)malloc(sizeof(int) * size + 1);
	while (count < size)
	{
		nbr[count] = ft_atoi(ret[count]);
		count++;
	}
	count = 0;
	while (ret[count])
		free(ret[count++]);
	free(ret);
	return (nbr);
}
