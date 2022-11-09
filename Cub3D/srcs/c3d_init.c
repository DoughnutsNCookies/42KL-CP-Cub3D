/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:54:26 by schuah            #+#    #+#             */
/*   Updated: 2022/11/09 21:29:29 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static void	init_mlx(t_gm *gm)
{
	gm->mlx = mlx_init();
	gm->win.ref = mlx_new_window(gm->mlx, WIN_W, WIN_H, "cub3D");
	gm->win.frame = 0;
	gm->win.mouse = 1;
	mlx_mouse_move(gm->win.ref, WIN_W / 2, WIN_H / 2);
}

static void	init_map(t_gm *gm)
{
	gm->map.n_img.ref = NULL;
	gm->map.e_img.ref = NULL;
	gm->map.s_img.ref = NULL;
	gm->map.w_img.ref = NULL;
	gm->map.d_img.ref = NULL;
	gm->map.door = NULL;
	gm->map.map = NULL;
	gm->map.c_rgb.hex = -1;
	gm->map.f_rgb.hex = -1;
	gm->map.main = ft_calloc(1, sizeof(t_img));
	gm->map.mini = ft_calloc(1, sizeof(t_img));
	gm->map.map_in = NULL;
}

static void	init_ply(t_gm *gm)
{
	gm->ply.e_dir = NOTSET;
	gm->ply.plane.x = 0;
	gm->ply.plane.y = 0.66;
	gm->ply.dir.x = 1;
	gm->ply.dir.y = 0;
}

void	c3d_init_gm(t_gm *gm)
{
	init_mlx(gm);
	init_map(gm);
	init_ply(gm);
}
