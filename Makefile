# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robriard <robriard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 11:06:38 by afreire-          #+#    #+#              #
#    Updated: 2020/04/30 14:07:10 by robriard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =	cub3d.c											\
		maths.c											\
		display.c										\
		move.c											\
		parsing/ft_parsing.c							\
		parsing/checkers/checkmap.c						\
		parsing/checkers/checkparsing.c					\
		parsing/Get-Next-Line/get_next_line.c			\
		parsing/Get-Next-Line/get_next_line_utils.c		\
		parsing/srcs/ft_error.c							\
		parsing/srcs/ft_squaremap.c						\
		parsing/srcs/ft_strcmp.c						\
<<<<<<< HEAD
		parsing/srcs/parsing_reader.c					
=======
		parsing/srcs/parsing_reader.c					\
		texture.c
>>>>>>> b90c05d10d6de8f495acd8f8b2ff613409cd56ac


OBJS = ${SRCS:.c=.o}

CC  = gcc

FLAGS =   -L includes/minilibx -lmlx -framework OpenGL -framework Appkit 
CFLAGS =  -Wall -Wextra -Werror -I includes/ -I includes/minilibx
RM  = rm -f

${NAME}	:	${OBJS}
	@${CC}	 -o ${NAME}  ${FLAGS} ${OBJS}

all:  ${NAME}

clean:	
	${RM}	${OBJS}

fclean:  clean
	${RM} ${NAME}

re: fclean all
	${RM}	${OBJS}
exe: re
	./${NAME} test.cub
.PHONY: all clean fclean re