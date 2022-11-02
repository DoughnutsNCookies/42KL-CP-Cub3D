/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:54:26 by schuah            #+#    #+#             */
/*   Updated: 2022/11/02 18:14:59 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	c3d_init_gm(t_gm *gm)
{
	gm->mlx = mlx_init();
	gm->win.ref = mlx_new_window(gm->mlx, WIN_H, WIN_W, "cub3D");
	gm->map.n_img.ref = NULL;
	gm->map.e_img.ref = NULL;
	gm->map.s_img.ref = NULL;
	gm->map.w_img.ref = NULL;
	gm->map.map = NULL;
	gm->map.c_rgb.hex = -1;
	gm->map.f_rgb.hex = -1;
}
