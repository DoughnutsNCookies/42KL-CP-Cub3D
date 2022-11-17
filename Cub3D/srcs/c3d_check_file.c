/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_check_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:11:28 by schuah            #+#    #+#             */
/*   Updated: 2022/11/17 20:20:18 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

char	**c3d_dup_map(char **map, int height)
{
	int		y;
	char	**output;

	output = ft_calloc(height + 1, sizeof(char *));
	y = -1;
	while (++y < height)
		output[y] = ft_strdup(map[y]);
	return (output);
}

static void	check_file_format(int ac, char **av)
{
	int		errno;

	if (ac < 2)
		c3d_fail_exit("./cub3D [map.cub]", NULL);
	errno = 0;
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4) != 0)
		c3d_fail_exit("Invalid file format", av[1]);
}

void	c3d_check_file(t_gm *gm, int ac, char **av)
{
	check_file_format(ac, av);
	c3d_check_element(gm, av);
	if (gm->map.map != NULL)
		c3d_check_map(gm, 0, 0);
	if (gm->ply.e_dir == NOTSET)
		c3d_fail_exit("No player set in map", NULL);
	gm->map.map_raw = c3d_dup_map(gm->map.map, gm->map.size.y);
	c3d_orient_map(gm);
}
