NAME = fdf
CC = cc
CFLAGS = -Wall -Werror -Wextra -I. -I$(MLX_PATH) -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(PRINTF_DIR)

SRCS = main.c \
		get_map.c \
		get_map_elements.c \
		3d_plot.c \
		color_trgb.c \
		projection.c \
		draw_maps.c \
		# free_func.c

OBJS = $(SRCS:.c=.o)

MLX_PATH = ./minilibx-linux
MLX_NAME = $(MLX_PATH)/minilibx.a
MLX_FLAGS = -lXext -lX11 -lm -lz

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = ./gnl
GNL_LIB = $(GNL_DIR)/libget_next_line.a

PRINTF_DIR = ./printf
PRINTF_LIB = $(PRINTF_DIR)/libprintf.a

all: $(MLX_NAME) $(LIBFT) $(GNL_LIB) $(PRINTF_LIB) $(NAME)

$(MLX_NAME):
	make -C $(MLX_PATH)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(GNL_LIB):
	make -C $(GNL_DIR)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(MLX_NAME) $(LIBFT) $(GNL_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_PATH) -lmlx $(MLX_FLAGS) \
		-L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lget_next_line -L$(PRINTF_DIR) -lprintf -o $(NAME)

%.o: %.c fdf.h gnl/get_next_line.h printf/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(PRINTF_LIB)
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	make -C $(PRINTF_DIR) clean

re: fclean all

rr:
	make re && make clean

bonus: all

.PHONY: all clean fclean re rr bonus
