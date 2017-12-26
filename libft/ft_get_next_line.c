/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <bsiguret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:41:28 by bsiguret          #+#    #+#             */
/*   Updated: 2017/12/11 17:13:07 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl	*gnl_lstnew(int fd)
{
	t_gnl	*lline;

	lline = (t_gnl*)malloc(sizeof(*lline));
	lline->buf = ft_strnew(1);
	lline->len = 1;
	lline->fd = fd;
	lline->next = NULL;
	return (lline);
}

static t_gnl	*get_validfile(t_gnl *gnl, int fd)
{
	t_gnl	*lline;

	while (gnl)
	{
		if (gnl->fd == fd)
			return (gnl);
		if (gnl->next == NULL)
		{
			lline = gnl_lstnew(fd);
			gnl->next = lline;
			return (lline);
		}
		gnl = gnl->next;
	}
	return (gnl);
}

static int		get_validbuf(t_gnl **cline, char **line)
{
	char	*tmp;
	char	*end;

	if ((end = ft_strchr((*cline)->buf, '\n')) != NULL)
	{
		*end = '\0';
		*line = ft_strdup((*cline)->buf);
		tmp = (*cline)->buf;
		(*cline)->buf = ft_strdup(end + 1);
		ft_strdel(&tmp);
		return (GNL_SUCCESS);
	}
	return (GNL_ERROR);
}

static int		read_file(t_gnl **cline, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while (((*cline)->len = read((*cline)->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[(*cline)->len] = '\0';
		tmp = ft_strjoin((*cline)->buf, buf);
		ft_strdel(&(*cline)->buf);
		(*cline)->buf = tmp;
		if (get_validbuf(cline, line) == 1)
			return (GNL_SUCCESS);
	}
	return (GNL_EOF);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl;
	t_gnl			*cline;

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (GNL_ERROR);
	if (!gnl)
		gnl = gnl_lstnew(fd);
	cline = get_validfile(gnl, fd);
	if (read_file(&cline, line) == GNL_SUCCESS)
		return (GNL_SUCCESS);
	if (cline->len == -1)
		return (GNL_ERROR);
	if (ft_strlen(cline->buf) == 0)
		return (GNL_EOF);
	if (get_validbuf(&cline, line) == GNL_SUCCESS)
		return (GNL_SUCCESS);
	else
	{
		*line = ft_strdup(cline->buf);
		ft_strclr(cline->buf);
		return (GNL_SUCCESS);
	}
	return (GNL_ERROR);
}
