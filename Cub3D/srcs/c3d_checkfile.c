/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_checkfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:11:28 by schuah            #+#    #+#             */
/*   Updated: 2022/11/02 12:29:32 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

/**
 * - Map must be closed/surrounded by walls, else return an error.
 * - Except for map content, each type of element can be separated by one or more
 * empty lines
 * - Except for the map content which always has to be the last, each type of
 * element can be set in any order in the file.
 * - Except for the map, each type of information from an element can be
 * separated by one or more space(s)
 * 
 * NO ./path_to_the_north_texture
 * SO ./path_to_the_south_texture
 * WE ./path_to_the_south_texture
 * EA ./path_to_the_south_texture
 * 
 * F 0,123,255
 * C 0,123,255
 */

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
}
