SOURCES = push_swap.c
OBJECTS = $(SOURCES:.c=.o)
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_DIR = libft

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
