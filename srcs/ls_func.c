/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:27:27 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/03 16:00:15 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls_data	*ft_ls_lstnew(char *name)
{
	t_ls_data *node;

	node = ft_memalloc(sizeof(t_ls_data));
	node->name = name;
	node->next = NULL;
	return (node);
}

void		ft_ls_addend(t_ls_data **head, t_ls_data *node)
{
	t_ls_data *temp;

	temp = *head;
	if (!*head)
		(*head) = node;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}
}

void		ft_ls_freeall(t_ls_data *head)
{
	t_ls_data *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
