CLIENT		= client
SERVER		= server
CLIENT_B	= bclient_bonus
SERVER_B	= bserver_bonus

LIBFT_DIR	= libft-improved
SRC_DIR		= src
INC_DIR		= inc

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf
LIBFT_FLAGS		= -L $(LIBFT_DIR) -lft
VALGRIND_FLAGS	= -O0 -g
#LEAKS_FLAGS	= -fsanitize=address -g3

.PHONY : all re clean fclean

all : $(CLIENT) $(SERVER) $(CLIENT_B) $(SERVER_B)

$(CLIENT) : $(SRC_DIR)/client.c
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) -I$(INC_DIR) $(SRC_DIR)/client.c -o $(CLIENT)

$(SERVER) : $(SRC_DIR)/server.c
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) -I$(INC_DIR) $(SRC_DIR)/server.c -o $(SERVER)

$(CLIENT_B) : $(SRC_DIR)/client_bonus.c
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) -I$(INC_DIR) $(SRC_DIR)/client_bonus.c -o $(CLIENT_B)

$(SERVER_B) : $(SRC_DIR)/server_bonus.c
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBFT_FLAGS) -I$(INC_DIR) $(SRC_DIR)/server_bonus.c -o $(SERVER_B)

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(CLIENT) $(CLIENT_B) $(SERVER) $(SERVER_B)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean

re : fclean all
