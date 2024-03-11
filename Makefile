# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 15:28:43 by esimpson          #+#    #+#              #
#    Updated: 2024/03/11 13:10:02 by esimpson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft

SRCS_PATH = srcs

LIBFT = $(LIBFT_PATH)/libft.a

INCLUDE = includes

SRC_FILES = $(SRCS_PATH)/minishell_main.c $(SRCS_PATH)/utils.c $(SRCS_PATH)/init_shell.c
 
SRC_OBJ = $(SRC_FILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRC_OBJ) 
	@make -C $(LIBFT_PATH) all
	@$(CC) $(CFLAGS) $(SRC_OBJ) -I$(INCLUDE) $(LIBFT) -o $(NAME)
	@echo "SUCCESSFULLY MADE $(words $(SRC_OBJ)) object files"

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -f $(SRC_OBJ) 

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME) 

re: fclean $(NAME) 

.PHONY:	all clean fclean re