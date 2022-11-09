/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:48:13 by schuah            #+#    #+#             */
/*   Updated: 2022/11/09 17:22:46 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static void	draw_verline(t_gm *gm, int i, int draw_start, int draw_end, int color)
{
	while (draw_start < draw_end)
	{
		mlx_pixel_put(gm->mlx, gm->win.ref, i, draw_start, color);
		draw_start++;
	}
}

void	c3d_render(t_gm *gm)
{
	int	x;

	x = -1;
	while (++x < WIN_W)
	{
		double cameraX = 2 * x / (double)WIN_W - 1;
		double rayDirX = gm->ply.dir.x + gm->ply.plane.x * cameraX;
		double rayDirY = gm->ply.dir.y + gm->ply.plane.y * cameraX;

		int map_x = (int)gm->ply.pos.x;
		int map_y = (int)gm->ply.pos.y;

		double side_dist_x;
		double side_dist_y;

		double delta_dist_x = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double delta_dist_y = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		double perp_wall_dist;

		int	step_x;
		int	step_y;

		int	hit = 0;
		int	side;

		if (rayDirX < 0)
		{
			step_x = -1;
			side_dist_x = (gm->ply.pos.x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - gm->ply.pos.x) * delta_dist_x;
		}
		if (rayDirY < 0)
		{
			step_y = -1;
			side_dist_y = (gm->ply.pos.y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - gm->ply.pos.y) * delta_dist_y;
		}

		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}

			if (gm->map.map[(int)map_y][(int)map_x] == '1')
				hit = 1;
		}

		if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);

		int	line_height = (int)(WIN_H / perp_wall_dist);

		int	draw_start = -line_height / 2 + WIN_H / 2;
		if (draw_start < 0)
			draw_start = 0;
		int	draw_end = line_height / 2 + WIN_H / 2;
		if (draw_end >= WIN_H)
			draw_end = WIN_H - 1;

		// CODE HERE IS FOR PIXEL TEXTURE
		int color = GREEN;
		switch(gm->map.map[map_y][map_x])
		{
			case 1:  color = RED;  break; //red
			case 2:  color = GREEN;  break; //green
			case 3:  color = BLUE;   break; //blue
			case 4:  color = TWHITE;  break; //white
			default: color = TBROWN; break; //yellow
		}
		if (side == 1)
			color = color / 2;
		draw_verline(gm, x, draw_start, draw_end, color);
		// drawBuffer(gm, x, draw_start, draw_end);

		//Code here is for sprite texture
		// unsigned int buffer[WIN_H][WIN_W];
		// unsigned int color;
		// int	texNum = gm->map.map[map_y][map_x] - 1;
		// double	wallX;
		// if (side == 0)
		// 	wallX = gm->ply.pos.y + perp_wall_dist * rayDirY;
		// else
		// 	wallX = gm->ply.pos.x + perp_wall_dist * rayDirX;
		// wallX -= floor((wallX));
		// int	texX = (int)(wallX * (double)texWidth);
		// if (side == 0 && rayDirX > 0)
		// 	texX = texWidth - texX - 1;
		// if (side == 1 && rayDirY < 0)
		// 	texX = texWidth - texX - 1;
		
		// double step = 1.0 * texHeight / line_height;
		// double texPos = (draw_start - WIN_H / 2 + line_height / 2) * step;
		// int y = draw_start;
		// while (y < draw_end)
		// {
		// 	int texY = (int)texPos & (texHeight - 1);
		// 	color = RED;
		// 	texPos += step;
		// 	y++;
		// }
		// draw_verline(gm, x, draw_start, draw_end, color);
	}
}

int	c3d_display(t_gm *gm)
{
	c3d_display_minimap(gm);
	c3d_render(gm);
	return (0);
}
