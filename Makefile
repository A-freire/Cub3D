# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robriard <robriard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 11:06:38 by afreire-          #+#    #+#              #
#    Updated: 2020/07/03 16:16:54 by robriard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CUB = test.cub

SRCS =	cub3d.c									\
	srcs/tools.c								\
	srcs/display.c								\
	srcs/move.c									\
	srcs/texture.c								\
	srcs/game.c									\
	srcs/sprites.c								\
	srcs/shift.c								\
	srcs/ft_bmp.c								\
	srcs/health.c								\
	srcs/speed.c								\
	srcs/game_on.c								\
	parsing/ft_parsing.c						\
	parsing/checkers/checkmap.c					\
	parsing/checkers/checkparsing.c				\
	parsing/checkers/checktp.c					\
	parsing/Get-Next-Line/get_next_line.c		\
	parsing/Get-Next-Line/get_next_line_utils.c	\
	parsing/srcs/ft_error.c						\
	parsing/srcs/ft_squaremap.c					\
	parsing/srcs/ft_strcmp.c					\
	parsing/srcs/parsing_reader.c				\
	parsing/srcs/ft_parsinginit.c				\
	srcs/read.c									\
	srcs/order.c								\
	srcs/bonus.c								\
	srcs/norme.c								\
	srcs/ft_asset.c


OBJS = ${SRCS:.c=.o}

CC  = gcc

FLAGS =   -L includes/minilibx -lmlx_Linux -lXext -lX11 -lm -lbsd -lmlx
CFLAGS =  -Wall -Wextra -Werror
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
	@(gcc -o ${NAME} -I includes/minilibx/ ${SRCS} includes/minilibx/libmlx.a ${FLAGS} ${CFLAGS})
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
	@(./${NAME} ${CUB})
	@echo "${GREEN}Programm Closed${RESET}"
	@(rm ${NAME})

help:
	@echo "${RED}===MAKFILE of Cub3D 42 project===${RESET}\n"
	@echo "${BLUE}all :${RESET} be the default value. Just compile SRCS in NAME."
	@echo "${BLUE}clean :${RESET} delete all objects files."
	@echo "${BLUE}fclean :${RESET} delete the executable NAME. he use clean"
	@echo "${BLUE}re :${RESET} compile the lasted version of the files OBJS in NAME. He use fclean and all."
	@echo "${BLUE}exe :${RESET} compile the lastead version of the files OBJS in NAME and execute the programm. He use re"


.PHONY: all clean fclean re exe help
