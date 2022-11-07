/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_image_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:44:03 by schuah            #+#    #+#             */
/*   Updated: 2022/11/07 17:46:09 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static void	change_color(t_gm *gm, int color, int pixel, char *addr)
{
	if (gm->map.main->end == 1)
	{
		addr[pixel + 0] = (color >> 24);
		addr[pixel + 1] = (color >> 16) & 0xFF;
		addr[pixel + 2] = (color >> 8) & 0xFF;
		addr[pixel + 3] = (color) & 0xFF;
	}
	else if (gm->map.main->end == 0)
	{
		addr[pixel + 0] = (color) & 0xFF;
		addr[pixel + 1] = (color >> 8) & 0xFF;
		addr[pixel + 2] = (color >> 16) & 0xFF;
		addr[pixel + 3] = (color >> 24);
	}
}

void	c3d_draw_block(t_gm *gm, int x, int y, int color)
{
	int	px;
	int	py;

	py = -1;
	while (++py < MMAP_PX)
	{
		px = -1;
		while (++px < MMAP_PX)
		{
			change_color(gm, color, (((y * MMAP_PX) + py) * gm->map.main->sl)
				+ (((x * MMAP_PX) + px) * 4), gm->map.main->addr);
		}
	}
}