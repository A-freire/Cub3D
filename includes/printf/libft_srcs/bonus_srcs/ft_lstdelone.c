/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:57:22 by robriard          #+#    #+#             */
/*   Updated: 2019/10/23 11:40:44 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdelone(t_list *lst, void (del)(void *))
{
	del(lst->content);
	free(lst->content);
	lst->content = NULL;
}
