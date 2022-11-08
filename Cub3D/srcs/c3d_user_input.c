/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_user_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:02:52 by schuah            #+#    #+#             */
/*   Updated: 2022/11/08 19:01:33 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static void	player_movement(t_gm *gm, int keycode)
{
	if (keycode == KEY_W)
		gm->ply.pos.y -= PLY_MVSPD;
	else if (keycode == KEY_A)
		gm->ply.pos.x -= PLY_MVSPD;
	else if (keycode == KEY_S)
		gm->ply.pos.y += PLY_MVSPD;
	else if (keycode == KEY_D)
		gm->ply.pos.x += PLY_MVSPD;
	else if (keycode == KEY_LEFT)
	{
		double	old_dir_x = gm->ply.dir.x;
		gm->ply.dir.x = gm->ply.dir.x * cos(PLY_ROTSPD) - gm->ply.dir.y * sin(PLY_ROTSPD);
		gm->ply.dir.y = old_dir_x * sin(PLY_ROTSPD) + gm->ply.dir.y * cos(PLY_ROTSPD);
		double	old_plane_x = gm->ply.plane.x;
		gm->ply.plane.x = gm->ply.plane.x * cos(PLY_ROTSPD) - gm->ply.plane.y * sin(PLY_ROTSPD);
		gm->ply.plane.y = old_plane_x * sin(PLY_ROTSPD) + gm->ply.plane.y * cos(PLY_ROTSPD);
	}
	else if (keycode == KEY_RIGHT)
	{
		double	old_dir_x = gm->ply.dir.x;
		gm->ply.dir.x = gm->ply.dir.x * cos(-PLY_ROTSPD) - gm->ply.dir.y * sin(-PLY_ROTSPD);
		gm->ply.dir.y = old_dir_x * sin(-PLY_ROTSPD) + gm->ply.dir.y * cos(-PLY_ROTSPD);
		double	old_plane_x = gm->ply.plane.x;
		gm->ply.plane.x = gm->ply.plane.x * cos(-PLY_ROTSPD) - gm->ply.plane.y * sin(-PLY_ROTSPD);
		gm->ply.plane.y = old_plane_x * sin(-PLY_ROTSPD) + gm->ply.plane.y * cos(-PLY_ROTSPD);
	}
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		printf("POS X: %f Y: %f\n", gm->ply.pos.x, gm->ply.pos.y);
}

static void	system_command(t_gm *gm, int keycode)
{
	return ;
	(void)gm;
	(void)keycode;
}

int	c3d_user_input(int keycode, t_gm *gm)
{
	if (keycode == KEY_ESC)
		c3d_success_exit();
	mlx_clear_window(gm->mlx, gm->win.ref);
	player_movement(gm, keycode);
	system_command(gm, keycode);
	c3d_display(gm);
	return (0);
}
