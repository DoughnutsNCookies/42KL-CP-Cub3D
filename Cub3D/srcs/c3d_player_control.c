/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:07:25 by schuah            #+#    #+#             */
/*   Updated: 2022/11/09 12:13:42 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	c3d_player_movement(t_gm *gm, int keycode)
{
	if (keycode == KEY_W)
		gm->ply.pos.y -= PLY_MVSPD;
	else if (keycode == KEY_A)
		gm->ply.pos.x -= PLY_MVSPD;
	else if (keycode == KEY_S)
		gm->ply.pos.y += PLY_MVSPD;
	else if (keycode == KEY_D)
		gm->ply.pos.x += PLY_MVSPD;
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		printf("POS X: %f Y: %f\n", gm->ply.pos.x, gm->ply.pos.y);
}

void	c3d_player_view(t_gm *gm, int keycode)
{
	double	dir_x;
	double	plane_x;
	double	rot_spd;

	rot_spd = PLY_ROTSPD;
	if (keycode == KEY_LEFT)
		rot_spd = -PLY_ROTSPD;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		dir_x = gm->ply.dir.x;
		gm->ply.dir.x = gm->ply.dir.x * cos(rot_spd)
			- gm->ply.dir.y * sin(rot_spd);
		gm->ply.dir.y = dir_x * sin(rot_spd)
			+ gm->ply.dir.y * cos(rot_spd);
		plane_x = gm->ply.plane.x;
		gm->ply.plane.x = gm->ply.plane.x * cos(rot_spd)
			- gm->ply.plane.y * sin(rot_spd);
		gm->ply.plane.y = dir_x * sin(rot_spd)
			+ gm->ply.plane.y * cos(rot_spd);
	}
}
