/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlim <edlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:03:54 by edlim             #+#    #+#             */
/*   Updated: 2022/12/06 15:11:18 by edlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->sl + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_verline(t_img *img, int i, t_gm *gm)
{
	char	*dest;
	double	y;
	int		newcolor;
	double	factor;

	y = 0;
	factor = ((double)(img->size.y - 1)
			/ (double)(gm->render.draw_end - gm->render.draw_start));
	while (gm->render.draw_start < gm->render.draw_end)
	{
		if (gm->render.draw_start >= 0 && gm->render.draw_start < WIN_H)
		{
			dest = img->addr + ((int)y * img->sl
					+ gm->render.tex_x * (img->bpp / 8));
			newcolor = *(unsigned int *)dest;
			my_mlx_pixel_put(&gm->map.imgw, i, gm->render.draw_start, newcolor);
		}
		gm->render.draw_start++;
		y = y + factor;
	}
}
