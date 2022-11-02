/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:54:17 by schuah            #+#    #+#             */
/*   Updated: 2022/11/02 21:28:16 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	print_ll(t_list **list)
{
	t_list	*node;

	node = *list;
	while (node != NULL)
	{
		ft_printf("|%s|\n", *(char **)node->content);
		node = node->next;
	}
}

void	print_da(char **array)
{
	int	i;

	i = -1;
	while (array[++i] != 0)
		ft_printf("|%s|\n", array[i]);
}
