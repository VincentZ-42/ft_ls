/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 11:22:23 by vzhao             #+#    #+#             */
/*   Updated: 2019/10/04 11:58:05 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#define CE(x) create_elem(x)

typedef struct		s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

t_list	*create_elem(int n)
{
	t_list *node = malloc(sizeof(t_list));

	node->data = n;
	node->next = NULL;
	return (node);
}

void	print_list(t_list *list)
{
	while (list != NULL)
	{
		printf(" %d ", list->data);
		list = list->next;
	}
	printf("\n");
}

void	free_list(t_list *list)
{
	t_list *temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

void	split(t_list *list, t_list **a, t_list **b)
{
	t_list *slow;
	t_list *fast;

	slow = list;
	fast = list->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = list;
	*b = slow->next;
	slow->next = NULL;
}

t_list	*sorting(t_list *a, t_list *b)
{
	if (!a)
		return (b);
	if (!b)
		return (a);

	t_list *ret = NULL;

	if (b->data - a->data > 0)
	{
		ret = a;
		ret->next = sorting(a->next, b);
	}
	else
	{
		ret = b;
		ret->next = sorting(a, b->next);
	}
	return (ret);
}

void	merge_sort(t_list **list)
{
	t_list *head;
	t_list *a;
	t_list *b;

	head = *list;
	if (!head || !head->next)
		return ;
	split(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*list = sorting(a, b);
}

int		main(void)
{
	t_list *head = CE(5);

	head->next = CE(10);
	head->next->next = CE(42);
	head->next->next->next = CE(100);
	head->next->next->next->next = CE(0);
	head->next->next->next->next->next = CE(42);

	printf("----unsorted\n");
	print_list(head);

	printf("------sorted\n");
	merge_sort(&head);
	print_list(head);

	free_list(head);
//	system("leaks a.out");
	return (1);
}
