/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:54:01 by robriard          #+#    #+#             */
/*   Updated: 2020/07/03 16:34:41 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2, int max)
{
	int i;

	i = 0;
	while ((s1[i] && s2[i]) || i < max)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
