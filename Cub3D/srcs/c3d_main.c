/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:57:41 by schuah            #+#    #+#             */
/*   Updated: 2022/11/04 12:52:42 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	main(int ac, char **av)
{
	t_gm	gm;

	c3d_init_gm(&gm);
	c3d_check_file(&gm, ac, av);
	c3d_hooks(&gm);
	mlx_put_image_to_window(gm.mlx, gm.win.ref, gm.map.n_img.ref, 0, 0);
	mlx_put_image_to_window(gm.mlx, gm.win.ref, gm.map.e_img.ref, 100, 0);
	mlx_put_image_to_window(gm.mlx, gm.win.ref, gm.map.s_img.ref, 200, 0);
	mlx_put_image_to_window(gm.mlx, gm.win.ref, gm.map.w_img.ref, 300, 0);
	if (gm.map.door != NULL)
		mlx_put_image_to_window(gm.mlx, gm.win.ref, gm.map.d_img.ref, 400, 0);
	print_da(gm.map.map);
	mlx_loop(gm.mlx);
	return (c3d_success_exit());
}
