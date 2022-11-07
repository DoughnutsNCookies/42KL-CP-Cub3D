/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:52:43 by schuah            #+#    #+#             */
/*   Updated: 2022/11/07 17:46:23 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static void	create_map(t_gm *gm)
{
	int	x;
	int	y;

	gm->map.main->ref = mlx_new_image(gm->mlx, gm->map.size.x * MMAP_PX,
			gm->map.size.y * MMAP_PX);
	gm->map.main->addr = mlx_get_data_addr(gm->map.main->ref, &gm->map.main->bpp, &gm->map.main->sl,
			&gm->map.main->end);
	y = -1;
	while (++y < gm->map.size.y)
	{
		x = -1;
		while (++x < gm->map.size.x)
		{
			if (gm->map.map[y][x] == '1')
				c3d_draw_block(gm, x, y, WHITE);
			else if (gm->map.map[y][x] == 'D')
				c3d_draw_block(gm, x, y, BROWN);
		}
	}
}

static void	create_minimap(t_gm *gm)
{
	return ;
	(void)gm;
}

void	c3d_display_minimap(t_gm *gm)
{
	create_map(gm);
	create_minimap(gm);
	mlx_put_image_to_window(gm->mlx, gm->win.ref, gm->map.main->ref, 0, 0);
	return ;
}
