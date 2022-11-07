/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_user_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:02:52 by schuah            #+#    #+#             */
/*   Updated: 2022/11/07 18:39:16 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	player_movement(t_gm *gm, int keycode)
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

int	c3d_user_input(int keycode, t_gm *gm)
{
	mlx_clear_window(gm->mlx, gm->win.ref);
	if (keycode == KEY_ESC)
		c3d_success_exit();
	player_movement(gm, keycode);
	c3d_display_minimap(gm);
	return (0);
}
