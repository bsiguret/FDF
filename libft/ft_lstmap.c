/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiguret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:37:17 by bsiguret          #+#    #+#             */
/*   Updated: 2017/11/09 20:43:34 by bsiguret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*tmp;
	t_list	*tmplst;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmplst = f(lst);
	if ((newlst = ft_lstnew(tmplst->content, tmplst->content_size)))
	{
		tmp = newlst;
		lst = lst->next;
		while (lst != NULL)
		{
			tmplst = (*f)(lst);
			if (!(tmp->next = ft_lstnew(tmplst->content, tmplst->content_size)))
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (newlst);
}
