# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sifreita <sifreita@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 07:03:34 by sifreita          #+#    #+#              #
#    Updated: 2022/06/13 07:07:25 by sifreita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${wildcard srcs/*.c}
TEXT = /MakeArt/${wildcard *.txt}
LIBRARIES = ${wildcard libraries/*.a}
FLAGS = -Wall -Werror -Wextra
INCS = includes/
NAME = so_long

${NAME}: ${SRCS}
	@clear
	@cat MakeArt/compiling.txt
	@sleep 1
	@gcc ${SRCS} ${LIBRARIES} ${FLAGS} -lmlx -framework OpenGL -framework AppKit -I${INCS} -o ${NAME}
	@clear
	@cat MakeArt/compiled.txt
	@sleep 0.5
	@clear

all: ${NAME}

clean:
	@clear
	@cat MakeArt/cleaning.txt
	@rm -rf ${NAME}
	@sleep 1
	@clear
	@cat MakeArt/cleaned.txt
	@sleep 0.5
	@clear

fclean: clean

re: fclean all

.PHONY: all bonus clean fclean re .c.o
