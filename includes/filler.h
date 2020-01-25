/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:33:48 by arkim             #+#    #+#             */
/*   Updated: 2020/01/23 10:23:33 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_map
{
	int				h;
	int				w;
	int				**data;
}					t_map;

typedef struct		s_place
{
	int				flag;
	int				n;
	int				min;
	t_point			p;
}					t_place;

typedef struct		s_filler
{
	char			me;
	char			enemy;
	t_map			map;
	t_map			token;
	t_place			place;
}					t_filler;

extern	t_point		g_zero;

/*
** 					init.c
*/

void				init_player(int fd, char *line, t_filler *f);
void				init_map(t_filler *f, char *line, int fd);
void				init_token(t_filler *f, char *line, int fd);

/*
** 					solve.c
*/

void				init_heat(t_filler *f);
void				explore(t_filler *f, t_point p);

/*
** 					placement.c
*/

void				explore(t_filler *f, t_point p);
void				placement(t_filler *f);

/*
** 					main.c
*/

void				main_loop(t_filler *f, int fd, char *line);
void				reset(t_filler *f);

#endif
