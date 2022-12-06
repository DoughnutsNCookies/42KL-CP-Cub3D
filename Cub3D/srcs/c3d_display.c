/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:48:13 by schuah            #+#    #+#             */
/*   Updated: 2022/12/06 15:17:51 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	renderdoor(t_gm *gm)
{
	t_img	*curimg;
	int		x;

	x = -1;
	while (++x < WIN_W)
	{
		set_variables(gm, x);
		check_steps(gm);
		while (gm->render.hit == 0)
		{
			if (gm->render.side_dist_x < gm->render.side_dist_y)
			{
				gm->render.side_dist_x += gm->render.delta_dist_x;
				gm->render.map_x += gm->render.step_x;
				gm->render.side = 0;
			}
			else
			{
				gm->render.side_dist_y += gm->render.delta_dist_y;
				gm->render.map_y += gm->render.step_y;
				gm->render.side = 1;
			}
			if ((gm->map.map[(int)gm->render.map_y][(int)gm->render.map_x] == 'D') ||
				gm->map.map[(int)gm->render.map_y][(int)gm->render.map_x] == '1')
				gm->render.hit = 1;
		}
		if (gm->render.side == 0)
			gm->render.perp_wall_dist = (gm->render.side_dist_x - gm->render.delta_dist_x);
		else
			gm->render.perp_wall_dist = (gm->render.side_dist_y - gm->render.delta_dist_y);
		curimg = &gm->map.d_img;
		set_length(gm);
		check_sides(gm, curimg);
		if (gm->map.map[(int)gm->render.map_y][(int)gm->render.map_x] == 'D')
			draw_verline(curimg, x, gm);
	}
	mlx_put_image_to_window(gm->mlx, gm->win.ref, gm->map.imgw.ref, 0, 0);
}

void	clearimgwindow(t_gm *gm)
{
	int	i;
	int	k;

	i = 0;
	while (i < WIN_W)
	{
		k = 0;
		while (k < WIN_H)
		{
			if (k < WIN_H / 2)
				my_mlx_pixel_put(&gm->map.imgw, i, k, gm->map.c_rgb.hex);
			else
				my_mlx_pixel_put(&gm->map.imgw, i, k, gm->map.f_rgb.hex);
			k++;
		}
		i++;
	}
}

int	c3d_display(t_gm *gm)
{
	clearimgwindow(gm);
	mlx_clear_window(gm->mlx, gm->win.ref);
	if (gm->win.mouse == 0)
		c3d_mouse_control(gm);
	c3d_render(gm);
	renderdoor(gm);
	c3d_display_minimap(gm);
	c3d_update_door(gm);
	return (0);
}
