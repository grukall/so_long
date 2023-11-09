CC = cc
FT_PRINTF_DIR = ./ft_printf
MINILIBX_DIR = ./minilibx_opengl
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

SRCS =	./get_next_line/get_next_line.c			\
		./get_next_line/get_next_line_utils.c	\
		so_long.c								\
		hooks.c									\
		check_maps.c							\
		check_maps_path.c						\
		make_map.c								\
		so_long_utils.c							\
		dfs.c									\

OBJS =	$(SRCS:%.c=%.o)

FT_PRINTF = libftprintf.a

MINILIBX = libmlx.a

all: $(FT_PRINTF) $(MINILIBX) $(NAME)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

$(NAME): $(FT_PRINTF_DIR)/$(FT_PRINTF) $(MINILIBX_DIR)/$(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(FT_PRINTF_DIR) -lftprintf -L$(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(FT_PRINTF_DIR) clean
	make -C $(MINILIBX_DIR) clean

fclean:
	make clean
	rm -f $(NAME)
	rm -f $(MINILIBX_DIR)/$(MINILIBX)
	rm -f $(FT_PRINTF_DIR)/$(FT_PRINTF)
	rm -f $(FT_PRINTF_DIR)/libft/libft.a

re:
	make fclean
	make all

.PHONY: all clean fclean re