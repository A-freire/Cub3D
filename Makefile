# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afreire- <afreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 11:06:38 by afreire-          #+#    #+#              #
#    Updated: 2020/02/24 11:38:08 by afreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =	cub3d.c \
		maths.c

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
	./${NAME}
.PHONY: all clean fclean re