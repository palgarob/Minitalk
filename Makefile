# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 17:23:53 by pepaloma          #+#    #+#              #
#    Updated: 2024/03/04 20:49:25 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR		= libft-improved
OBJ_DIR_C		= obj_c
OBJ_DIR_S		= obj_s
SRC_DIR_C		= src_c
SRC_DIR_S		= src_s
BIN_DIR			= bin

CLIENT		= $(BIN_DIR)/client
SERVER		= $(BIN_DIR)/server

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -fsanitize=address -g3
RM				= rm -rf
LIBFT_LINK_FLAGS= -I$(LIBFT_DIR) -L $(LIBFT_DIR) -lft
#VALGRIND_FLAGS	= -O0 -g

FILES_C	= $(notdir $(wildcard src_c/*.c))
SRC_C	= $(addprefix $(SRC_DIR_C)/, $(FILES_C))
OBJ_C	= $(addprefix $(OBJ_DIR_C)/, $(FILES_C:.c=.o))
FILES_S	= $(notdir $(wildcard src_s/*.c))
SRC_S	= $(addprefix $(SRC_DIR_S)/, $(FILES_S))
OBJ_S	= $(addprefix $(OBJ_DIR_S)/, $(FILES_S:.c=.o))

.PHONY : all re clean fclean

all : $(CLIENT) $(SERVER)

$(CLIENT) : $(OBJ_C)
	$(MAKE) -C $(LIBFT_DIR)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(LIBFT_LINK_FLAGS) $(INC_FLAGS) $(OBJ_C) -o $(CLIENT)

$(SERVER) : $(OBJ_S)
	$(MAKE) -C $(LIBFT_DIR)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(LIBFT_LINK_FLAGS) $(INC_FLAGS) $(OBJ_S) -o $(SERVER)

$(OBJ_DIR_C)/%.o : $(SRC_DIR_C)/%.c
	mkdir -p $(OBJ_DIR_C)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_S)/%.o : $(SRC_DIR_S)/%.c
	mkdir -p $(OBJ_DIR_S)
	$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(BIN_DIR_C) $(BIN_DIR_S)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR_C) $(OBJ_DIR_S)

re : fclean all
