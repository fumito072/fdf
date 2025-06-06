NAME = libprintf.a  # "lib" を追加

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_format.c ft_write_char.c ft_write_hexadecimal.c ft_write_num.c ft_write_pointer.c ft_write_str.c ft_write_unsigned.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	/usr/bin/libtool -static -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
