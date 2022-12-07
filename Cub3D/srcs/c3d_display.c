/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:48:13 by schuah            #+#    #+#             */
/*   Updated: 2022/12/06 17:56:25 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

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
