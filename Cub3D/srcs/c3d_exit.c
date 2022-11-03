/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:16:44 by schuah            #+#    #+#             */
/*   Updated: 2022/11/03 12:23:40 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	c3d_fail_exit(char *str)
{
	ft_dprintf(2, "Error\n%s\n", str);
	system("leaks -q cub3D");
	exit(1);
	return (1);
}

int	c3d_success_exit(void)
{
	ft_printf("Thanks for playing!\n");
	system("leaks -q cub3D");
	exit(0);
	return (0);
}
