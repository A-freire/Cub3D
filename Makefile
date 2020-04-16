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
		move.c

OBJS = ${SRCS:.c=.o}

CC  = gcc

FLAGS =   -L includes/minilibx -lmlx -framework OpenGL -framework Appkit 
CFLAGS =  -Wall -Wextra -Werror -I includes/ -I includes/minilibx
RM  = rm -f

${NAME}	:	${OBJS}
<<<<<<< HEAD
	${CC}	 -o ${NAME}  ${FLAGS} ${OBJS}
=======
	@${CC}	 -o ${NAME}  ${FLAGS} ${OBJS}
>>>>>>> f5335835a8f02767c37b99212640242dd4724123

all:  ${NAME}

clean:	
	${RM}	${OBJS}

fclean:  clean
	${RM} ${NAME}

re: fclean all
	${RM}	${OBJS}
exe: re
<<<<<<< HEAD
	./${NAME} test.cub
=======
	./${NAME}
>>>>>>> f5335835a8f02767c37b99212640242dd4724123
.PHONY: all clean fclean re