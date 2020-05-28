# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robriard <robriard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 11:06:38 by afreire-          #+#    #+#              #
#    Updated: 2020/05/28 11:46:00 by robriard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =	cub3d.c											\
		srcs/tools.c									\
		srcs/display.c									\
		srcs/move.c										\
		srcs/texture.c									\
		srcs/game.c										\
		srcs/sprites.c									\
		srcs/shift.c									\
		srcs/ft_bmp.c									\
		srcs/ft_memset.c								\
		parsing/ft_parsing.c							\
		parsing/checkers/checkmap.c						\
		parsing/checkers/checkparsing.c					\
		parsing/Get-Next-Line/get_next_line.c			\
		parsing/Get-Next-Line/get_next_line_utils.c		\
		parsing/srcs/ft_error.c							\
		parsing/srcs/ft_squaremap.c						\
		parsing/srcs/ft_strcmp.c						\
		parsing/srcs/parsing_reader.c					


OBJS = ${SRCS:.c=.o}

CC  = gcc

FLAGS =   -L includes/minilibx -lmlx -framework OpenGL -framework Appkit 
CFLAGS =  -Wall -Wextra -Werror -I includes/ -I includes/minilibx
RM  = rm -f

BLACK		:= $(shell tput -Txterm setaf 0)
RED			:= $(shell tput -Txterm setaf 1)
GREEN		:= $(shell tput -Txterm setaf 2)
YELLOW		:= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	:= $(shell tput -Txterm setaf 4)
PURPLE		:= $(shell tput -Txterm setaf 5)
BLUE		:= $(shell tput -Txterm setaf 6)
WHITE		:= $(shell tput -Txterm setaf 7)
RESET		:= $(shell tput -Txterm sgr0)

$(NAME):
	@echo "${YELLOW}Compilation...${RESET}"
	@($(CC) $(CFLAGS) $(SRCS) $(FLAGS) -o $(NAME))
	@echo "${GREEN}Compilation OK${RESET}"

all:  ${NAME}

clean:	
	@echo "${RED}deleting ojbects${RESET}"
	@(${RM}	${OBJS})

fclean:  clean
	@echo "${RED}deleting executable${RESET}"
	@(${RM} ${NAME})

re: fclean all clean
	
exe: re
	@echo "${YELLOW}Execution${RESET}"
	@(./${NAME} test.cub)
	@echo "${GREEN}Programm Closed${RESET}"

help:
	@echo "${RED}===MAKFILE of Cub3D 42 project===${RESET}\n"
	@echo "${BLUE}all :${RESET} be the default value. Just compile SRCS in NAME."
	@echo "${BLUE}clean :${RESET} delete all objects files."
	@echo "${BLUE}fclean :${RESET} delete the executable NAME. he use clean"
	@echo "${BLUE}re :${RESET} compile the lasted version of the files OBJS in NAME. He use fclean and all."
	@echo "${BLUE}exe :${RESET} compile the lastead version of the files OBJS in NAME and execute the programm. He use re"


.PHONY: all clean fclean re help