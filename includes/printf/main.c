/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:58:44 by robriard          #+#    #+#             */
/*   Updated: 2020/05/20 15:58:19 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	int size1;
	int size2;
	size1 = 0;
	size2 = 0;

	int		a;
	int		b;
	char	c;
	int		d;
	int		e;
	int		f;
	int		g;
	int		h;
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;
	char	*n;
	char	*o;
	char	*p;
	char	*q;
	char	*r;
	char	*s;
	char	*t;
	char	*u;
	int		v[1];
	a = -4;
	b = 0;
	c = 'a';
	d = 2147483647;
	e = -2147483648;
	f = 42;
	g = 25;
	h = 4200;
	i = 8;
	j = -12;
	k = 123456789;
	l = 0;
	m = -12345678;
	n = "abcdefghijklmnop";
	o = "-a";
	p = "-12";
	q = "0";
	r = "%%";
	s = "-2147483648";
	t = "0x12345678";
	u = "-0";
	v[0] = 0;
	
	a = 12;
	b = 18;
	size1 =ft_printf("\033[1;34m || \033[0m\n");
	printf("\n");
	size2 = printf("\033[1;34m || \033[0m\n");

	if (size1 == size2)
		printf("SIZE ->	\033[1;32m %d	[OK] \033[0m\n", size1);
	else
		printf("SIZE ->\033[1;31m	[KO]\nFT_PRINTF_SIZE = %d	/	PRINTF_SIZE = %d\033[0m\n", size1, size2);
	printf ("\n");
	return (0);
}
