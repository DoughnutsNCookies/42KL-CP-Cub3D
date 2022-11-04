/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_user_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:02:52 by schuah            #+#    #+#             */
/*   Updated: 2022/11/04 14:07:02 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	c3d_user_input(int keycode, t_gm *gm)
{
	if (keycode == KEY_ESC)
		c3d_success_exit();
	return (0);
	(void)gm;
}
