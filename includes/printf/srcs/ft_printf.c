/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:08:15 by robriard          #+#    #+#             */
/*   Updated: 2020/05/20 18:05:59 by afreire-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_convchr(char c)
{
	char	*cmp;
	int		i;

	cmp = "cspuxXdi";
	i = 0;
	while (cmp[i])
	{
		if (c == cmp[i])
			return (i);
		i++;
	}
	return (-1);
}

static int		ft_isflag(char c)
{
	char	*cmp;
	int		i;

	cmp = "*.0123456789+-";
	i = 0;
	while (cmp[i])
	{
		if (cmp[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void		ft_fill_tab(int (*tab[8])(va_list arg, t_flag flag))
{
	tab[0] = ft_convert_to_char;
	tab[1] = ft_convert_to_string;
	tab[2] = ft_convert_to_pointer;
	tab[3] = ft_convert_to_unsigne;
	tab[4] = ft_convert_to_lowhex;
	tab[5] = ft_convert_to_upphex;
	tab[6] = ft_convert_to_int;
	tab[7] = ft_convert_to_int;
}

static int		ft_convert(const char *str, va_list arg)
{
	int			i;
	int			size;
	t_flag		flag;
	int			(*tab[8])(va_list arg, t_flag flag);

	ft_fill_tab(tab);
	flag = ft_check_flag(str, arg);
	i = 1;
	while (ft_isflag(str[i]) && str[i])
		i++;
	if (ft_convchr(str[i]) == -1)
		size = ft_convert_to_exept(str[i], flag);
	else
		size = tab[ft_convchr(str[i])](arg, flag);
	return (size);
}

int				ft_printf(const char *str, ...)
{
	int		i;
	int		size;
	int		buf;
	va_list	(arg);

	va_start(arg, str);
	size = 0;
	i = 0;
	while (str[i])
	{
		size = (str[i] != '%') ? size + ft_intputchar(str[i]) : size;
		if (str[i] == '%')
		{
			size = size + ft_convert(str + i, arg);
			i++;
			buf = i;
			while (ft_isflag(str[i]) && str[i])
				i++;
			if (str[i] == '\0')
				i = buf;
		}
		i++;
	}
	va_end(arg);
	return (size);
}
