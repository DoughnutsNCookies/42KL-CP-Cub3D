/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_renderdoor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:56:00 by edlim             #+#    #+#             */
/*   Updated: 2022/12/06 18:02:43 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static void	check_hit(t_gm *gm)
{
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
		if ((gm->map.map[(int)gm->render.map_y][(int)gm->render.map_x] == 'D')
			|| gm->map.map[(int)gm->render.map_y][(int)gm->render.map_x] == '1')
			gm->render.hit = 1;
	}
}

void	renderdoor(t_gm *gm)
{
	t_img	*curimg;
	int		x;

	x = -1;
	while (++x < WIN_W)
	{
		set_variables(gm, x);
		check_steps(gm);
		check_hit(gm);
		if (gm->render.side == 0)
			gm->render.perp_wall_dist = (gm->render.side_dist_x
					- gm->render.delta_dist_x);
		else
			gm->render.perp_wall_dist = (gm->render.side_dist_y
					- gm->render.delta_dist_y);
		curimg = &gm->map.d_img;
		set_length(gm);
		check_sides(gm, curimg);
		if (gm->map.map[(int)gm->render.map_y][(int)gm->render.map_x] == 'D')
			draw_verline(curimg, x, gm);
	}
	mlx_put_image_to_window(gm->mlx, gm->win.ref, gm->map.imgw.ref, 0, 0);
}
