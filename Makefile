NAME = ft_retro

FLAGS = -Wall -Werror -Wextra

OBJ = Boss.o Bullet.o Enemy.o Game.o main.o Player.o


SRC = Boss.cpp Bullet.cpp Enemy.cpp Game.cpp main.cpp Player.cpp

all : $(NAME)

$(NAME) : $(OBJ)
	clang++ -lncurses $(FLAG) $(SRC) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
