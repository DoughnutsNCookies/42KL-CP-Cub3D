/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:27:11 by schuah            #+#    #+#             */
/*   Updated: 2022/11/02 14:22:32 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	c3d_all_elements_present(t_gm *gm, int fd)
{
	close(fd);
	if (!gm->map.n_img.ref || !gm->map.e_img.ref
		|| !gm->map.s_img.ref || !gm->map.w_img.ref
		|| gm->map.c_rgb.hex < 0 || gm->map.f_rgb.hex < 0)
		c3d_fail_exit("Missing element");
}

int	c3d_map_contents_only(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'E'
			&& str[i] != 'S' && str[i] != 'W' && str[i] != ' ' && str[i] != '\t'
			&& (str[i] != '\n' || i == 0))
			return (0);
	}
	return (1);
}