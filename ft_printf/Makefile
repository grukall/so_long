LIBFT_DIR = ./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS =	ft_printf.c			\
		ft_printf_utils.c	\
		parameters.c		\
		parameters2.c		\
		parameters_utils.c

OBJS =	$(SRCS:%.c=%.o)
LIBFT = libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFT)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/$(LIBFT)

re:
	make fclean
	make all

.PHONY: all clean fclean re