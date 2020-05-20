/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robriard <robriard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:09:18 by robriard          #+#    #+#             */
/*   Updated: 2020/02/05 18:41:05 by robriard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft_srcs/libft.h"

typedef struct	s_flag
{
	int	prec;
	int ldc;
	int option;
	int plus;
}				t_flag;

int				ft_intputchar(char c);
int				ft_intputstr(char *str);
void			ft_putstr(char *str);
void			ft_putnbr(int n);
void			ft_putunbr(unsigned int n);
int				ft_intputnbr(int n);
char			*ft_convertbase(unsigned int nbr);
char			*ft_luconvertbase(uintptr_t nbr);
int				ft_atoi_base(char *str, char *base);
int				verif_base(char *base);
int				ft_atoi(const char *s);
char			*ft_utoa(unsigned int n);
int				ft_power_of_ten(int arg);
int				ft_upower_of_ten(unsigned arg);
int				ft_lupower_of_ten(uintptr_t arg);
int				ft_while(int i, int j, char c);
int				ft_printf(const char *str, ...);
t_flag			ft_check_flag(char const *str, va_list arg);
t_flag			ft_check_flag2(char const *s, va_list arg, t_flag f, int i);
t_flag			ft_ldc_value(char const *str, int i, va_list arg, t_flag f);
t_flag			ft_check_dot(char const *str, int i, t_flag f, va_list arg);
int				ft_charset(char c);
int				ft_check_ldc(char const *str, int i, va_list arg);
int				ft_convert_to_exept(char c, t_flag flag);
int				ft_convert_to_char(va_list arg, t_flag flag);
int				ft_convert_to_string(va_list arg, t_flag flag);
int				ft_last_part_of_zero(char *str, int size, int len, t_flag flag);
int				ft_last_part_of_one(char *str, int size, int len, t_flag flag);
int				ft_convert_to_int(va_list arg, t_flag flag);
int				ft_print_int_option_zero2(t_flag flag, int arg, int power,
											int i);
int				ft_print_int_option_one2(t_flag flag, int arg, int power,
											int i);
int				ft_convert_to_lowhex(va_list arg, t_flag flag);
int				ft_convert_to_upphex(va_list arg, t_flag flag);
int				ft_convert_to_unsigne(va_list arg, t_flag flag);
int				ft_convert_to_pointer(va_list arg, t_flag flag);
int				ft_print_option_one_part_one(int power, t_flag flag);
int				ft_print_option_one_part_two(int power, t_flag flag);
int				ft_print_option_zero_part2(int power, t_flag flag, int i);

#endif
