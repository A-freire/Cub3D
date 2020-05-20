/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:16:32 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:40:40 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(f)(void *))
{
	t_list	*crt;

	crt = ft_lstnew(f(lst->content));
	while (lst->next)
	{
		crt = crt->next;
		lst = lst->next;
		crt = ft_lstnew(f(lst->content));
	}
	return (crt);
}
