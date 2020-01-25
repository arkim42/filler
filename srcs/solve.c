/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 17:38:12 by arkim             #+#    #+#             */
/*   Updated: 2020/01/23 10:22:44 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		put_heat(t_filler *f, int **data, t_point p, int i)
{
	if ((p.y > 0 && data[p.y - 1][p.x] == i) \
		|| (p.y > 0 && p.x + 1 < f->map.w && data[p.y - 1][p.x + 1] == i) \
		|| (p.x + 1 < f->map.w && data[p.y][p.x + 1] == i) \
		|| (p.y + 1 < f->map.h && p.x + 1 < f->map.w \
								&& data[p.y + 1][p.x + 1] == i) \
		|| (p.y + 1 < f->map.h && data[p.y + 1][p.x] == i) \
		|| (p.y + 1 < f->map.h && p.x > 0 && data[p.y + 1][p.x - 1] == i) \
		|| (p.x > 0 && data[p.y][p.x - 1] == i) \
		|| (p.y > 0 && p.x > 0 && data[p.y - 1][p.x - 1] == i))
		data[p.y][p.x] = i + 1;
}

void			init_heat(t_filler *f)
{
	t_point		p;
	int			n;
	int			i;

	n = (f->map.w > f->map.h) ? f->map.w : f->map.h;
	i = 0;
	while (++i < n)
	{
		p.y = -1;
		while (++p.y < f->map.h)
		{
			p.x = -1;
			while (++p.x < f->map.w)
				if (f->map.data[p.y][p.x] == 1000)
					put_heat(f, f->map.data, p, i);
		}
	}
}
