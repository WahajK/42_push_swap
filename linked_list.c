/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:10:01 by muhakhan          #+#    #+#             */
/*   Updated: 2025/03/27 02:29:55 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
}	t_list;

t_node	*ft_lstnew(int data)
{
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	if (!temp)
		return (0);
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

int	ft_lstsize(t_node *lst)
{
	int	ret;

	ret = 0;
	while (lst && ++ret)
		lst = lst->next;
	return (ret);
}

void	ft_lstadd_front(t_node **head, t_node **tail, t_node *new)
{
	if (!new)
		return ;
	if (!(*tail) && !(*head))
	{
		*head = new;
		*tail = new;
	}
	else if (!(*head)->next)
	{
		(*tail)->prev = new;
		new->next = *tail;
		*head = new;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
}

void	ft_lstadd_back(t_node **head, t_node **tail, t_node *new)
{
	if (!new)
		return ;
	if (!(*tail) && !(*head))
	{
		*head = new;
		*tail = new;
	}
	else if (!(*head)->next)
	{
		(*head)->next = new;
		new->prev = *head;
		*tail = new;
	}
	else
	{
		(*tail)->next = new;
		new->prev = *tail;
		*tail = new;
	}
}

void	ft_lstdelone(t_node *node)
{
	if (node)
		free(node);
}

void	ft_lstclear(t_node **head, t_node **tail)
{
	if (!head || !*head)
		return ;
	ft_lstclear(&(*head)->next, tail);
	ft_lstdelone(*head);
	*head = NULL;
	*tail = NULL;
}

t_list	*ft_lstinit(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

// int	main(void)
// {
// 	t_node *temp;
// 	t_list *list = malloc(sizeof(t_list));
// 	if (!list)
// 		return (1);
// 	list->head = NULL;
// 	list->tail = NULL;
// 	ft_lstadd_back((&(list->head)), &(list->tail), ft_lstnew(1));
// 	ft_lstadd_back((&(list->head)), &(list->tail), ft_lstnew(2));
// 	ft_lstadd_back((&(list->head)), &(list->tail), ft_lstnew(3));
// 	ft_lstadd_back((&(list->head)), &(list->tail), ft_lstnew(4));
// 	ft_lstadd_front((&(list->head)), &(list->tail), ft_lstnew(0));
// 	temp = list->head;
// 	while (temp)
// 	{
// 		printf("%d ", temp->data);
// 		temp = temp->next;
// 	}
// 	ft_lstclear(&(list->head), &(list->tail));
// 	free(list);
// }