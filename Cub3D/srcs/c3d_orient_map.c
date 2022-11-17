/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_orient_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:47:58 by schuah            #+#    #+#             */
/*   Updated: 2022/11/17 20:39:41 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static void	replace_map(t_gm *gm, char **old_map, t_ivct old, t_ivct new)
{
	while (++old.x < gm->map.size.x)
	{
		new.x = 0;
		old.y = gm->map.size.y;
		gm->map.map[new.y] = ft_calloc(gm->map.size.y + 1, sizeof(char));
		while (--old.y >= 0)
		{
			gm->map.map[new.y][new.x] = old_map[old.y][old.x];
			if (gm->map.map[new.y][new.x] == 'N'
				|| gm->map.map[new.y][new.x] == 'E'
				|| gm->map.map[new.y][new.x] == 'S'
				|| gm->map.map[new.y][new.x] == 'W')
			{
				gm->ply.pos.x = new.x;
				gm->ply.pos.y = new.y;
			}
			new.x++;
		}
		new.y++;
	}
	gm->map.map[new.y] = 0;
}

static void	rotate_right(t_gm *gm, char **map, int count)
{
	t_ivct	new;
	t_ivct	old;

	ft_freesplit(gm->map.map);
	gm->map.map = ft_calloc(gm->map.size.x + 1, sizeof(char *));
	new.y = 0;
	old.x = -1;
	replace_map(gm, map, old, new);
	ft_swap(&gm->map.size.x, &gm->map.size.y);
	if (count < 4)
		rotate_right(gm, c3d_dup_map(gm->map.map, gm->map.size.y), count + 1);
	ft_freesplit(map);
}

void	c3d_orient_map(t_gm *gm)
{
	if (gm->ply.e_dir == WEST)
		rotate_right(gm, c3d_dup_map(gm->map.map_raw, gm->map.size.y), WEST);
	else if (gm->ply.e_dir == EAST)
		rotate_right(gm, c3d_dup_map(gm->map.map_raw, gm->map.size.y), EAST);
	else if (gm->ply.e_dir == SOUTH)
		rotate_right(gm, c3d_dup_map(gm->map.map_raw, gm->map.size.y), SOUTH);
}