/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_check_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:59:18 by schuah            #+#    #+#             */
/*   Updated: 2022/11/02 17:55:01 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	trim_back_spaces(char *str, int len)
{
	if (len == 0 || str[len] != ' ')
		return ;
	if (str[len] == ' ')
		str[len] = '\0';
	trim_back_spaces(str, len - 1);
}

static void	add_map(t_list **map_list, char *str)
{
	t_list	*node;
	char	*temp;
	int		i;

	i = -1;
	node = ft_lstnew(ft_calloc(1, sizeof(char *)));
	temp = ft_calloc(1, sizeof(char *));
	while (str[++i] != '\0')
	{
		if (str[i] == '\t')
			temp = ft_strjoin_free(temp, "    ");
		else if (str[i] != '\n')
			temp = ft_append_char(temp, str[i]);
	}
	trim_back_spaces(temp, ft_strlen(temp) - 1);
	ft_memcpy(node->content, &temp, sizeof(char *));
	ft_lstadd_back(map_list, node);
}

static int	get_map_width(t_list **map_list)
{
	t_list	*node;
	size_t	max;

	node = *map_list;
	max = 0;
	while (node != NULL)
	{
		if (max < ft_strlen(*(char **)node->content))
			max = ft_strlen(*(char **)node->content);
		node = node->next;
	}
	return (max);
}

static void	map_is_valid(t_gm *gm, t_list **map_list)
{
	static int	checked = 0;

	if (checked)
		return ;
	checked = 1;
	gm->map.y = ft_lstsize(*map_list);
	gm->map.x = get_map_width(map_list);
	print_ll(map_list);
}

void	c3d_check_map(t_gm *gm, char *str, int fd)
{
	static int		mapmode = 0;
	static t_list	*map_list = NULL;

	if (c3d_map_contents_only(str) == 0)
	{
		free(str);
		if (mapmode && str != NULL)
			c3d_fail_exit("Extra new line at end of file");
		return ;
	}
	c3d_all_elements_present(gm);
	mapmode = 1;
	add_map(&map_list, str);
	free(str);
	c3d_check_map(gm, get_next_line(fd), fd);
	map_is_valid(gm, &map_list);
}
