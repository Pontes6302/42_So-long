SRCS = ${wildcard *.c}
TEXT = /MakeArt/${wildcard *.txt}
FLAGS = 
INCS = so_long.h
NAME = so_long

${NAME}: ${SRCS}
	@clear
	@cat MakeArt/compiling.txt
	@sleep 1
	@gcc ${SRCS} $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -I ${INCS} -o $(NAME)
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