/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esouza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:29:39 by esouza            #+#    #+#             */
/*   Updated: 2018/09/15 10:48:57 by esouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		line_len(char *s, char ch)
{
	size_t			len;

	len = 0;
	while (s[len] != ch && s[len] != '\0')
		len++;
	return (len);
}

static void			get_line(t_gnl *g, char **line, int fd)
{
	size_t			len;

	len = line_len(g->tmp, '\n');
	*line = ft_strnew(len);
	if (line_len(g->tmp, '\n'))
	{
		free(g->rem[fd]);
		*line = ft_memmove(*line, g->tmp, len);
		g->rem[fd] = ft_strsub(g->tmp, len + 1, ft_strlen(g->tmp) - (len));
		free(g->tmp);
	}
	else if (line_len(g->tmp, '\n') == 0)
	{
		*line = ft_memmove(*line, g->tmp, len);
		free(g->rem[fd]);
		if (ft_strlen(g->tmp) < 1)
			g->rem[fd] = NULL;
		else
			g->rem[fd] = ft_strsub(g->tmp, 1, ft_strlen(g->tmp) - 1);
		free(g->tmp);
	}
}

static void			get_result(t_gnl *g, int fd)
{
	g->leaks = g->tmp;
	g->tmp = ft_strjoin(g->rem[fd], g->tmp);
	free(g->leaks);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl g;

	if (line == NULL)
		return (0);
	if (g.rem == NULL)
		g.rem = (char**)malloc(sizeof(char*) * OPEN_MAX);
	if (g.rem == NULL)
		return (0);
	g.tmp = ft_strnew(0);
	while (1)
	{
		g.leaks = g.tmp;
		if ((g.ret = read(fd, g.buff, BUFF_SIZE)) == -1)
			return (0);
		g.buff[g.ret] = '\0';
		g.tmp = ft_strjoin(g.tmp, g.buff);
		free(g.leaks);
		if ((ft_strchr(g.tmp, '\n') != NULL) || g.ret == 0)
			break ;
	}
	if (g.rem[fd])
		get_result(&g, fd);
	get_line(&g, line, fd);
	return (g.ret > 0 || g.rem[fd]);
}
