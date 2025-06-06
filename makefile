NAME = fdf
CC = clang
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft -Ignl -Iprintf -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lglfw -framework OpenGL

SRCS = main.c \
	get_map.c \
	get_map_elements.c \
	3d_plot.c \
	color_trgb.c \
	projection.c \
	draw_map_gl.c \
	free_func.c \
	motion.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = ./gnl
GNL_LIB = $(GNL_DIR)/libget_next_line.a

PRINTF_DIR = ./printf
PRINTF_LIB = $(PRINTF_DIR)/libprintf.a

FRAMEWORKS = -framework OpenGL -lglfw

all: $(LIBFT) $(GNL_LIB) $(PRINTF_LIB) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GNL_LIB):
	make -C $(GNL_DIR)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) \
		-L./libft -lft \
		-L./gnl -lget_next_line \
		-L./printf -lprintf \
		-L/opt/homebrew/lib -lglfw -framework OpenGL \
		-o $(NAME)



%.o: %.c fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
