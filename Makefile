CC = cc

BONUS_CLIENT_SRC = bonus_client.c
BONUS_SERVER_SRC = bonus_server.c
ifdef BONUS
	CLIENT_SRC += $(BONUS_CLIENT_SRC)
	SERVER_SRC += $(BONUS_SERVER_SRC)
endif
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

all: message $(NAME_CLIENT) $(NAME_SERVER)

message:
	@echo "\033[0;32mInitializing server and client\033[0m"

$(NAME_CLIENT): $(CLIENT_OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(CLIENT_OBJ) $(LIBFT) $(PRINTF)

$(NAME_SERVER): $(SERVER_OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SERVER_OBJ) $(LIBFT) $(PRINTF)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -s -C $(PRINTF_DIR)

clean:
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re message
