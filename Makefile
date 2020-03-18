# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 11:06:38 by afreire-          #+#    #+#              #
#    Updated: 2020/03/05 14:32:41 by afreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =	cub3d.c \
		maths.c \
		display.c \
		move.c \
		./parsing/checking/ft_checkmap.c \
		./parsing/checking/ft_checkparsing.c \
		./parsing/Get-Next-Line/get_next_line_utils.c \
		./parsing/Get-Next-Line/get_next_line.c \
		./parsing/other/ft_countmap.c \
		./parsing/other/ft_error.c \
		./parsing/other/ft_finalmap.c \
		./parsing/other/ft_ismap.c \
		./parsing/other/ft_strncmp.c \
		./parsing/reader/ft_readparsing.c \
		./parsing/reader/parsing_reader.c \
		./parsing/ft_parsing.c \

OBJS = ${SRCS:.c=.o}

CC  = gcc

FLAGS =   -L includes/minilibx -lmlx -framework OpenGL -framework Appkit
CFLAGS =  -Wall -Wextra -Werror -I includes/ -I includes/minilibx
RM  = rm -f

${NAME}	:	${OBJS}
	@(${CC}	 -o ${NAME}  ${FLAGS} ${OBJS})

all:  ${NAME}

clean:	
	@(${RM}	${OBJS})

fclean:  clean
	@(${RM} ${NAME})

re: fclean all
	@(${RM}	${OBJS})
exe: re
	@(./${NAME})
.PHONY: all clean fclean re