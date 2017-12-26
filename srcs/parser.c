/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 04:40:23 by bsiguret          #+#    #+#             */
/*   Updated: 2017/12/26 04:40:31 by bsiguret         ###   ########.fr       */
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
	if (!fd || !file)
		ft_putendl("open() error");
	while (get_next_line((int const)fd, &line))
		count++;
	close(fd);
	ret = (char**)malloc(sizeof(char*) * (count + 1));
	fd = open(file, O_RDONLY);
	while (get_next_line((int const)fd, &line) && i < count)
	{
		ret[i] = ft_strdup(line);
		free(line);
		i++;
	}
	ret[i] = NULL;
	close(fd);
	return (ret);
}

int			size_line(char *str)
{
	int		cnt;
	int		in_substring;

	in_substring = 0;
	cnt = 0;
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
		count++;
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
