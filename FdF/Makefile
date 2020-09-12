# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmorgana <tmorgana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/15 00:08:11 by tmorgana          #+#    #+#              #
#    Updated: 2020/08/15 00:34:29 by tmorgana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

OBJ = $(patsubst %.c, %.o, $(SRC))

SRC = ./src/main.c ./src/draw.c ./src/color.c ./src/read_write.c ./src/key.c ./src/data.c

INC = fdf.h

LIB = ./libft/libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc -g $(FLAGS) -o $(NAME) $^ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(LIB) -I $(INC) 

%.o:%.c
	@gcc $(FLAGS) -c $^ -o $@ -I $(INC)

run: 
	@gcc -g $(SRC) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(LIB) -I $(INC) -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./libft 
	/bin/rm -f $(NAME)

re: fclean all
