/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:15:48 by arkim             #+#    #+#             */
/*   Updated: 2020/01/23 10:23:24 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point g_zero = {
	0, 0
};

void			init_player(int fd, char *line, t_filler *f)
{
	get_next_line(fd, &line);
	if (line && !ft_strncmp(line, "$$$ exec p", 10))
	{
		f->me = (line[10] == '1') ? 'O' : 'X';
		f->enemy = (line[10] == '1') ? 'X' : 'O';
		free(line);
	}
	else
		ft_puterror("bad player\n");
}

static void		convert(t_filler *f, char *line, int *data)
{
	int			len;
	int			i;

	len = ft_strlen(line);
	i = -1;
	while (++i < len)
	{
		if (line[i] == '.')
			data[i] = 1000;
		else
			data[i] = (line[i] == f->me) ? -2 : 1;
	}
}

void			init_map(t_filler *f, char *line, int fd)
{
	int			i;

	get_next_line(fd, &line);
	if (!ft_strncmp(line, "Plateau ", 8))
	{
		f->map.h = ft_atoi(line + 8);
		f->map.w = ft_atoi(line + 8 + ft_nbrlen(f->map.h));
		free(line);
	}
	f->map.data = (int **)malloc(sizeof(int *) * f->map.h);
	i = -1;
	get_next_line(fd, &line);
	free(line);
	while (++i < f->map.h && get_next_line(fd, &line))
	{
		f->map.data[i] = (int *)malloc(sizeof(int) * f->map.w);
		convert(f, line + 4, f->map.data[i]);
		free(line);
	}
}

void			init_token(t_filler *f, char *line, int fd)
{
	int			i;

	get_next_line(fd, &line);
	if (!ft_strncmp(line, "Piece ", 6))
	{
		f->token.h = ft_atoi(line + 6);
		f->token.w = ft_atoi(line + 6 + ft_nbrlen(f->token.h));
		free(line);
	}
	f->token.data = (int **)malloc(sizeof(int *) * f->token.h);
	i = -1;
	while (++i < f->token.h && get_next_line(fd, &line))
	{
		f->token.data[i] = (int *)malloc(sizeof(int) * f->token.w);
		convert(f, line, f->token.data[i]);
		free(line);
	}
}
