NAME = fillit

FLAGS = -Wall -Werror -Wextra

SRC = fillit.c \
	  input_checker.c \
	  ft_list.c \
	  ft_place.c \
	  save_places.c \
	  display_grid.c \
	  utils.c \
	  ft_lib.c \

HEADER = fillit.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o : %.c
	gcc $(TAGS) -c $<

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
