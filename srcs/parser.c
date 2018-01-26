/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 04:40:23 by bsiguret          #+#    #+#             */
/*   Updated: 2018/01/26 13:45:30 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		**read_file(char *file)
{
	char	*line;
	char	**ret;
	int		count;
	int		i;
	int		fd;

	i = 0;
	count = 0;
	fd = open(file, O_RDONLY);
	count = ft_isread_file(fd, count);
	ret = (char**)malloc(sizeof(char*) * (count + 1));
	fd = open(file, O_RDONLY);
	while (get_next_line((int const)fd, &line) && i < count)
	{
		ret[i] = ft_strdup(line);
		ft_strcat(ret[i], "  0");
		free(line);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

int			size_line(char *str)
{
	int		cnt;
	int		in_substring;

	in_substring = 0;
	cnt = 0;
	if (str == NULL)
		map_error();
	while (*str != '\0')
	{
		if (in_substring == 1 && *str == ' ')
			in_substring = 0;
		if (in_substring == 0 && *str != ' ')
		{
			in_substring = 1;
			cnt++;
		}
		str++;
	}
	return (cnt);
}

int			nb_line(char **stock)
{
	int		count;

	count = 0;
	while (stock[count])
	{
		count++;
	}
	if (count < 2)
	{
		ft_putendl("Error, invalid amount of lines");
		exit(1);
	}
	return (count);
}

int			check_file(char **stock)
{
	int		size;

	size = size_line(stock[0]);
	while (*stock)
	{
		if (size_line(*stock) < size)
			return (0);
		stock++;
	}
	return (1);
}
