/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_door.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:14:49 by schuah            #+#    #+#             */
/*   Updated: 2022/11/23 17:52:29 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static void	fade_door(t_gm *gm)
{
	int		trans;
	t_dvct	px;
	int		pixel;

	trans = gm->win.frame * 255 / DOOR_SPD;
	px.y = -1;
	while (++px.y < gm->map.d_img.size.y)
	{
		px.x = -1;
		while (++px.x < gm->map.d_img.size.x)
		{
			pixel = (px.y * gm->map.d_img.sl) + (px.x * 4);
			if (gm->map.d_img.end == 1)
				gm->map.d_img.addr[pixel + 0] = trans;
			else if (gm->map.d_img.end == 0)
				gm->map.d_img.addr[pixel + 3] = trans;
		}
	}
}

void	c3d_update_door(t_gm *gm)
{
	static int	playback = 1;

	if (gm->win.playing == 0)
		return ;
	gm->win.frame += playback;
	fade_door(gm);
	if (gm->win.frame >= DOOR_SPD || gm->win.frame <= 0)
	{
		gm->win.playing = 0;
		playback *= -1;
	}
}

void	c3d_door_state(t_gm *gm, int keycode)
{
	if (keycode != KEY_E)
		return ;
	gm->map.door_state = gm->map.door_state == 0;
	gm->win.playing = 1;
}
