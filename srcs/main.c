/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:34:17 by arkim             #+#    #+#             */
/*   Updated: 2020/01/23 10:23:58 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void			main_loop(t_filler *f, int fd, char *line)
{
	init_map(f, line, fd);
	init_token(f, line, fd);
	init_heat(f);
	placement(f);
	reset(f);
}

void			reset(t_filler *f)
{
	int			i;

	i = -1;
	while (++i < f->map.h)
		free(f->map.data[i]);
	free(f->map.data);
	i = -1;
	while (++i < f->token.h)
		free(f->token.data[i]);
	free(f->token.data);
	ft_bzero(&f->place, sizeof(t_place));
	f->place.min = 1000;
}

int				main(void)
{
	t_filler	f;
	char		*line;
	int			fd;

	line = NULL;
	fd = 0;
	init_player(fd, line, &f);
	printf("zone1\n");
	while (1)
		main_loop(&f, fd, line);
	return (0);
}
