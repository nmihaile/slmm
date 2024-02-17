COLOR_GREEN  = \033[0;92m
COLOR_CYAN   = \033[0;96m
COLOR_RESET  = \033[0m

NAME	= slmm
CC		= cc
CFLAGS	= -Wall -Wextra -Werror    -Wunreachable-code -Ofast     # -g  -fsanitize=address   #  -Wunreachable-code -Ofast

SRC_DIR	= src/

SRCS	= main.c error.c flags.c init1.c loader1.c hooks.c expand.c update.c movement.c map.c renderer.c utils1.c
OBJS	= $(addprefix $(SRC_DIR), $(SRCS:.c=.o))

MLXPATH = ./MLX42/build/
MLXLIB  = mlx42

.SILENT:

all: $(NAME)

$(NAME): libft mlx42 $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME) -L$(MLXPATH) -l$(MLXLIB) -ldl -lglfw -lm
	echo "$(COLOR_GREEN)SUCCESS ✓ $(COLOR_RESET) Compilation succeded."
	echo "$(COLOR_CYAN)Run slmm with:$(COLOR_RESET) make run, make start, make exec, make r or ./slmm"
	echo "$(COLOR_CYAN)Help:$(COLOR_RESET) ./slmm --help"
	echo "$(COLOR_CYAN)Have fun, and let's start building…$(COLOR_RESET)"


mlx42:
	git clone https://github.com/codam-coding-college/MLX42.git
	cd MLX42 && cmake -B build && cmake --build build -j4

libft:
	cd libft && make

clean:
	cd libft && make clean
	rm -f $(OBJS)

fclean: clean
	cd libft && make fclean
	rm -f $(NAME)

mlxclean: fclean
	rm -Rf MLX42

re: fclean all

t: $(NAME)
	./$(NAME)

ret: fclean clean t

r:
	./$(NAME)

run: r
start: run
exec: run

.PHONY: libft r
