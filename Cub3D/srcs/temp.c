/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:54:17 by schuah            #+#    #+#             */
/*   Updated: 2022/11/04 13:40:50 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	print_ll(t_list **list)
{
	t_list	*node;

	node = *list;
	ft_printf("\nNormal linked list:\n");
	while (node != NULL)
	{
		ft_printf("|%s|\n", *(char **)node->content);
		node = node->next;
	}
}

void	print_dl(t_list **list)
{
	t_list	*node;
	int		i;

	node = *list;
	i = 0;
	ft_printf("\nDoor linked list:\n");
	while (node != NULL)
	{
		ft_printf("i: %d| x: %d\t| y: %d\t|\n", i++,
			((t_ivct *)node->content)->x, ((t_ivct *)node->content)->y);
		node = node->next;
	}
}

void	print_da(char **array)
{
	int	i;

	i = -1;
	ft_printf("\nDouble array:\n");
	while (array[++i] != 0)
		ft_printf("|%s|\n", array[i]);
}
