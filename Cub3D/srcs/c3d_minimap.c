/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:52:43 by schuah            #+#    #+#             */
/*   Updated: 2022/11/07 22:05:38 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static void	create_map(t_gm *gm)
{
	int	x;
	int	y;

	gm->map.main->ref = mlx_new_image(gm->mlx, gm->map.size.x * MMAP_PX,
			gm->map.size.y * MMAP_PX);
	gm->map.main->addr = mlx_get_data_addr(gm->map.main->ref,
			&gm->map.main->bpp, &gm->map.main->sl, &gm->map.main->end);
	y = -1;
	while (++y < gm->map.size.y)
	{
		x = -1;
		while (++x < gm->map.size.x)
		{
			if (gm->map.map[y][x] == '1')
				c3d_draw_block(gm, x, y, TWHITE);
			else if (gm->map.map[y][x] == '0')
				c3d_draw_block(gm, x, y, TGREY);
			else if (gm->map.map[y][x] == 'D')
				c3d_draw_block(gm, x, y, TBROWN);
		}
	}
}

// static void	copy_pixel(t_gm *gm, int pixel_in)
// {
// 	static int	x;
// 	static int	y;
// 	int			pixel;
	
// }

static void	create_minimap(t_gm *gm)
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;

	gm->map.mini->ref = mlx_new_image(gm->mlx, gm->map.size.x * MMAP_PX,
			gm->map.size.y * MMAP_PX);
	gm->map.mini->addr = mlx_get_data_addr(gm->map.mini->ref,
			&gm->map.mini->bpp, &gm->map.mini->sl, &gm->map.mini->end);
	x = (gm->ply.pos.x * MMAP_PX) - (MMAP_PX * (MMAP_W / 2)) - 1;
	max_x = (gm->ply.pos.x * MMAP_PX) + (MMAP_PX * ((MMAP_W / 2) + 1));
	while (++x <= max_x)
	{
		y = (gm->ply.pos.y * MMAP_PX) - (MMAP_PX * (MMAP_H / 2)) - 1;
		max_y = (gm->ply.pos.y * MMAP_PX) + (MMAP_PX * ((MMAP_H / 2) + 1));
		while (++y <= max_y)
		{
			// copy_pixel(gm, (y * gm->map.mini->sl) + (x * 4));
		}
	}
}

void	c3d_display_minimap(t_gm *gm)
{
	create_map(gm);
	create_minimap(gm);
	mlx_clear_window(gm->mlx, gm->win.ref);
	mlx_put_image_to_window(gm->mlx, gm->win.ref, gm->map.n_img.ref, 500, 0);
	mlx_put_image_to_window(gm->mlx, gm->win.ref, gm->map.main->ref, 0, 0);
	mlx_pixel_put(gm->mlx, gm->win.ref, gm->ply.pos.x * 15 + 7,
		gm->ply.pos.y * 15 + 7, GREEN);
	return ;
}
