/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 07:27:49 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/13 06:47:23 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int				find_pos(char *str, char ptr)
{
	int		i;

	i = 0;
	while ((unsigned int)i < ft_strlen(str))
	{
		if (!(str[i] == ptr))
			i++;
		if (str[i] == ptr)
			break ;
	}
	return (i);
}

char					*clean_str(char *str)
{
	char	*ret;
	char	*ptr;

	ptr = NULL;
	if (!(ptr = ft_strchr((const char*)str, ',')))
		ret = "0x000000";
	else
		ret = ft_strsub((const char*)str, (find_pos(str, ',') + 1),
				ft_strlen(str));
	return (ret);
}

char					*remove_prefix(char *str)
{
	char	*ret;
	char	*ptr;

	ptr = NULL;
	if (!(ptr = ft_strchr((const char*)str, 'x')) ||
			find_pos(str, 'x') != 1 || str[0] != '0')
		return (str);
	else
	{
		ret = ft_strsub((const char*)str, 2, ft_strlen(str));
		return (ret);
	}
	return (NULL);
}

static unsigned long	*ft_getnbr_color(int size, t_point *alpha, char *str)
{
	char				**ret;
	unsigned long		*nbr;
	int					count;

	count = 0;
	ret = ft_strsplit(str, ' ');
	nbr = (unsigned long*)malloc(sizeof(unsigned long) * (size + 1));
	while (count < size)
	{
		nbr[count] = ft_atoi_base(remove_prefix(clean_str(ret[count])), 16);
		if (nbr[count] == 0)
		{
			if (alpha[count].z <= 0)
				nbr[count] = ft_atoi_base(COLOR1, 16);
			else if (alpha[count].z >= 1 && alpha[count].z <= 8)
				nbr[count] = ft_atoi_base(COLOR2, 16);
			else if (alpha[count].z >= 9 && alpha[count].z <= 14)
				nbr[count] = ft_atoi_base(COLOR3, 16);
			else
				nbr[count] = ft_atoi_base(COLOR4, 16);
		}
		count++;
	}
	return (nbr);
}

unsigned long			**get_color_data(int endl, int size,
		t_point **alpha, char **stock)
{
	unsigned long		**ret;
	int					index;

	index = 0;
	ret = (unsigned long**)malloc(sizeof(unsigned long*) * (endl + 1));
	while (index < endl)
	{
		ret[index] = ft_getnbr_color(size, *alpha, *stock);
		index++;
		stock++;
		alpha++;
	}
	return (ret);
}
