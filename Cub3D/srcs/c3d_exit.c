/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:16:44 by schuah            #+#    #+#             */
/*   Updated: 2022/11/07 17:40:49 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	c3d_fail_exit(char *msg, char *details)
{
	ft_dprintf(2, "Error\n");
	ft_dprintf(2, "%s", msg);
	if (details != NULL)
		ft_dprintf(2, ": |%s|", details);
	ft_dprintf(2, "\n");
	system("leaks -q cub3D");
	exit(1);
	return (1);
}

int	c3d_success_exit(void)
{
	ft_printf("Thanks for playing!\n");
	// system("leaks -q cub3D");
	exit(0);
	return (0);
}
