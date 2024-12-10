# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
NAME_CLIENT = client
NAME_SERVER = server

# Rules
all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(CLIENT_OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(CLIENT_OBJ) $(LIBFT) $(PRINTF)

$(NAME_SERVER): $(SERVER_OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SERVER_OBJ) $(LIBFT) $(PRINTF)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re