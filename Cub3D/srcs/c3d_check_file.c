/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_check_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:11:28 by schuah            #+#    #+#             */
/*   Updated: 2022/11/03 21:05:17 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

static void	check_file_format(int ac, char **av)
{
	int		errno;

	if (ac < 2)
		c3d_fail_exit("./cub3D [map.cub]");
	errno = 0;
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4) != 0)
		c3d_fail_exit("Invalid file format");
}

void	c3d_check_file(t_gm *gm, int ac, char **av)
{
	check_file_format(ac, av);
	c3d_check_element(gm, av);
	if (gm->map.map != NULL)
		c3d_check_map(gm, 0, 0);
	if (gm->ply.e_dir == NOTSET)
		c3d_fail_exit("No player set in map");
	print_dl(&gm->map.door);
}
