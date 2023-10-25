/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:46:42 by averdejo          #+#    #+#             */
/*   Updated: 2023/04/03 20:18:42 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lista;
	t_list	*nodo;

	if (!lst || !f || !del)
		return (NULL);
	lista = NULL;
	while (lst)
	{
		nodo = ft_lstnew(lst->content);
		if (!nodo)
		{
			ft_lstclear(&lista, del);
			return (NULL);
		}
		nodo->content = f(nodo->content);
		ft_lstadd_back(&lista, nodo);
		lst = lst->next;
	}
	return (lista);
}
