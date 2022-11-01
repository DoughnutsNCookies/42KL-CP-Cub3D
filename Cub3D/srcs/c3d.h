/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:57:57 by schuah            #+#    #+#             */
/*   Updated: 2022/11/01 14:56:09 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_H
# define C3D_H

# include "../libft/srcs/libft.h"
# include <mlx.h>

/* Mac key codes */
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define EXIT_EVENT	17
# define EXIT_MASK	0

/* Player prefs */
# define WIN_H		1280
# define WIN_W		800

/* Vector struct */
typedef struct s_vct
{
	int	x;
	int	y;
}	t_vct;

/* RGB struct */
typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	hex;
}	t_rgb;

/* Image struct */
typedef struct s_img
{
	void	*ref;
	t_vct	size;
}	t_img;

/* Window struct */
typedef struct s_win
{
	void	*ref;
	t_vct	size;
}	t_win;

/* Map struct */
typedef struct s_map
{
	t_rgb	c_rgb;
	t_rgb	f_rgb;
	t_img	n_img;
	t_img	e_img;
	t_img	s_img;
	t_img	w_img;
}	t_map;

/* Gamemaster struct*/
typedef struct s_gm
{
	void	*mlx;
	t_win	win;
	t_map	map;
}	t_gm;

void	c3d_init_gm(t_gm *gm);

void	c3d_check_file(t_gm *gm, int ac, char **av);

void	check_element(t_gm *gm, char **av);

int		c3d_fail_exit(char *str);
int		c3d_success_exit(void);

void 	c3d_hooks(t_gm *gm);

#endif
