/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:59:26 by muhakhan          #+#    #+#             */
/*   Updated: 2025/03/09 04:11:53 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

t_list	*ft_lstnew(int data)
{
	t_list *temp;

	temp = malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

void	ft_lstadd_back(t_list **head, int data)
{
	t_list	*node;
	t_list	*temp;

	node = ft_lstnew(data);
	if (!(*head))
		*head = node;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
		node->prev = temp;
		temp = node;
	}
}

void	ft_lstadd_front(t_list **head, int data)
{
	t_list	*node;

	node = ft_lstnew(data);
	node->next = *head;
	(*head)->prev = node;
	*head = node;
}

int	ft_lstsize(t_list *head)
{
	int	count;

	count = 0;
	while (head && ++count)
		head = head->next;
	return (count);
}

int	main(void)
{
	t_list	*head;
	t_list	*tail;

	head = NULL;
	ft_lstadd_back(&head, 1);
	ft_lstadd_back(&head, 2);
	printf("%d", head->data);
	printf("%d", head->next->prev->data);
}