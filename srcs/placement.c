/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 00:13:44 by arkim             #+#    #+#             */
/*   Updated: 2020/01/23 10:20:21 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		placement_temp(t_filler *f, int n, int overlap, t_point p, int min)
{
	if ((overlap == 1) && (f->place.flag == 0 || f->place.n >= n))
	{
		if (f->place.flag && f->place.n == n)
		{
			f->place.n = (min < f->place.min) ? n : f->place.n;
			f->place.p = (min < f->place.min) ? p : f->place.p;
			f->place.min = (min < f->place.min) ? min : f->place.min;
		}
		else
		{
			f->place.n = n;
			f->place.p = p;
			f->place.min = min;
		}
		f->place.flag = 1;
	}
}

void			explore(t_filler *f, t_point p)
{
	int			overlap;
	int			n;
	int			min;
	t_point		i;

	n = 0;
	overlap = 0;
	i.y = -1;
	min = 1000;
	while (++i.y < f->token.h)
	{
		i.x = -1;
		while (++i.x < f->token.w)
		{
			if (f->map.data[p.y + i.y][p.x + i.x] == 1 \
							&& f->token.data[i.y][i.x] == 1)
				return ;
			if (f->map.data[p.y + i.y][p.x + i.x] == -2 \
							&& f->token.data[i.y][i.x] == 1)
				overlap += 1;
			else
			{
				n += f->map.data[p.y + i.y][p.x + i.x] \
						* f->token.data[i.y][i.x];
				if (f->token.data[i.y][i.x] == 1)
					min = (min > f->map.data[p.y + i.y][p.x + i.x]) \
							? f->map.data[p.y + i.y][p.x + i.x] : min;
			}
		}
	}
	placement_temp(f, n, overlap, p, min);
}

void			placement(t_filler *f)
{
	t_point		i;

	i.y = -1;
	while ((++i.y + f->token.h) <= f->map.h)
	{
		i.x = -1;
		while ((++i.x + f->token.w) <= f->map.w)
			explore(f, i);
	}
	if (f->place.flag == 1)
	{
		ft_putnbr_fd(f->place.p.y, 1);
		write(1, " ", 1);
		ft_putnbr_fd(f->place.p.x, 1);
		write(1, "\n", 1);
	}
	else
	{
		write(1, "0 0\n", 4);
		exit(0);
	}
}
