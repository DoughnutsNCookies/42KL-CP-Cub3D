/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:30:19 by schuah            #+#    #+#             */
/*   Updated: 2022/11/07 18:46:09 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	c3d_hooks(t_gm *gm)
{
	mlx_hook(gm->win.ref, EXIT_EVENT, EXIT_MASK, &c3d_success_exit, NULL);
	mlx_hook(gm->win.ref, KD_EVENT, KEY_PRESS, &c3d_user_input, gm);
	mlx_loop_hook(gm->mlx, &c3d_display, gm);
	mlx_loop(gm->mlx);
}
