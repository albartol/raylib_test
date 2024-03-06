CC:=gcc

CFLAGS:=-Wall -Wextra -Werror -O3

LIBS:=-lraylib -lopengl32 -lgdi32 -lwinmm

NAME:=raylib_test.exe

SRC=src/raylib_test.c src/show_info.c src/draw_frame.c src/get_input.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re