# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 14:59:01 by robriard          #+#    #+#              #
#    Updated: 2020/05/20 18:10:34 by afreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF_NAME = libftprintf.a

LIB_NAME = libft.a

EXE_NAME = ft_printf



PRINTF_SRCS =	./srcs/ft_printf.c									\
				./srcs/other/ft_check_flags.c						\
				./srcs/other/ft_check_flags2.c						\
				./srcs/other/ft_printer_function.c					\
				./srcs/other/ft_printer_function2.c					\
				./srcs/other/ft_power_of_ten.c						\
				./srcs/other/ft_utoa.c								\
				./srcs/other/ft_convertbase.c						\
				./srcs/other/ft_luconvertbase.c						\
				./srcs/convertor_function/ft_convert_to_char.c		\
				./srcs/convertor_function/ft_convert_to_int.c		\
				./srcs/convertor_function/ft_convert_to_int2.c		\
				./srcs/convertor_function/ft_convert_to_string.c	\
				./srcs/convertor_function/ft_convert_to_string2.c	\
				./srcs/convertor_function/ft_convert_to_lowhex.c	\
				./srcs/convertor_function/ft_convert_to_upphex.c	\
				./srcs/convertor_function/ft_convert_to_unsigne.c	\
				./srcs/convertor_function/ft_convert_to_exept.c		\
				./srcs/convertor_function/ft_convert_to_pointer.c	\
				./srcs/convertor_function/ft_convert_to_pointer2.c	\

LIB_SRCS =	./libft_srcs/first_part_srcs/ft_atoi.c				\
			./libft_srcs/first_part_srcs/ft_isalpha.c			\
			./libft_srcs/first_part_srcs/ft_itoa.c				\
			./libft_srcs/first_part_srcs/ft_memcpy.c			\
			./libft_srcs/first_part_srcs/ft_putendl_fd.c		\
			./libft_srcs/first_part_srcs/ft_strchr.c			\
			./libft_srcs/first_part_srcs/ft_strnstr.c			\
			./libft_srcs/first_part_srcs/ft_tolower.c			\
			./libft_srcs/first_part_srcs/ft_bzero.c				\
			./libft_srcs/first_part_srcs/ft_isascii.c			\
			./libft_srcs/first_part_srcs/ft_memccpy.c			\
			./libft_srcs/first_part_srcs/ft_memmove.c			\
			./libft_srcs/first_part_srcs/ft_putnbr_fd.c			\
			./libft_srcs/first_part_srcs/ft_strdup.c			\
			./libft_srcs/first_part_srcs/ft_strlen.c			\
			./libft_srcs/first_part_srcs/ft_strrchr.c			\
			./libft_srcs/first_part_srcs/ft_toupper.c			\
			./libft_srcs/first_part_srcs/ft_calloc.c			\
			./libft_srcs/first_part_srcs/ft_isdigit.c			\
			./libft_srcs/first_part_srcs/ft_memchr.c			\
			./libft_srcs/first_part_srcs/ft_memset.c			\
			./libft_srcs/first_part_srcs/ft_putstr_fd.c			\
			./libft_srcs/first_part_srcs/ft_strjoin.c			\
			./libft_srcs/first_part_srcs/ft_strmapi.c			\
			./libft_srcs/first_part_srcs/ft_strtrim.c			\
			./libft_srcs/first_part_srcs/ft_isalnum.c			\
			./libft_srcs/first_part_srcs/ft_isprint.c			\
			./libft_srcs/first_part_srcs/ft_memcmp.c			\
			./libft_srcs/first_part_srcs/ft_putchar_fd.c		\
			./libft_srcs/first_part_srcs/ft_split.c				\
			./libft_srcs/first_part_srcs/ft_strlcat.c			\
			./libft_srcs/first_part_srcs/ft_strncmp.c			\
			./libft_srcs/first_part_srcs/ft_substr.c			\
			./libft_srcs/first_part_srcs/ft_strlcpy.c			\


LIB_OBJ = $(LIB_SRCS:.c=.o)

PRINTF_OBJ = $(PRINTF_SRCS:.c=.o) $(LIB_OBJ)

CFLAGS += -Wall -Werror -Wextra -I/.includes

all: $(PRINTF_NAME)

$(PRINTF_NAME): $(PRINTF_OBJ)
	ar rc $(PRINTF_NAME) $(PRINTF_OBJ)
	ranlib $(PRINTF_NAME)

clean:
	rm -f $(PRINTF_OBJ) $(LIB_OBJ)

aclean: all clean

fclean : clean
	rm -f $(PRINTF_NAME) $(LIB_NAME)

re: fclean all

bonus: $(OBJ_BONUS)
	ar rc $(NAME) $(OBJ_BONUS)
	ranlib $(NAME)

lib: $(LIB_NAME)

$(LIB_NAME): $(LIB_OBJ)
	ar rc $(LIB_NAME) $(LIB_OBJ)
	ranlib $(LIB_NAME)

libclean: lib clean

delete: 
	rm -f $(PRINTF_NAME) $(LIB_NAME) $(EXE_NAME)

compil: aclean
	gcc -Wall -Wextra -Werror $(PRINTF_NAME) main.c -o $(EXE_NAME)

exe: aclean
	gcc printf_main.c $(PRINTF_NAME) -o $(EXE_NAME)
	rm -rf $(PRINTF_NAME)
	./$(EXE_NAME)
	rm $(EXE_NAME)
	
.PHONY: all re clean aclean fclean bonus lib libclean delete compil exe
