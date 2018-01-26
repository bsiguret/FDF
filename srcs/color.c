/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 07:27:49 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/26 14:44:25 by bsiguret         ###   ########.fr       */
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
	{
		ret = ft_strsub((const char*)str, (find_pos(str, ',') + 1),
				ft_strlen(str));
	}
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
	char				*strcpy;
	char				*tmp;
	int					count;

	count = 0;
	ret = ft_strsplit(str, ' ');
	nbr = (unsigned long*)malloc(sizeof(unsigned long) * (size + 1));
	while (count < size)
	{
		tmp = clean_str(ret[count]);
		strcpy = remove_prefix(tmp);
		if (ft_strcmp(tmp, "0x000000") < 0 || ft_strcmp(tmp, "0x000000") > 0)
			free(tmp);
		nbr[count] = ft_atoi_base(strcpy, 16);
		free(strcpy);
		if (nbr[count] == 0)
		{
			ft_isnbr_color(nbr, alpha, count);
		}
		count++;
	}
	ft_freeret(ret);
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
