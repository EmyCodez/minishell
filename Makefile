# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emilin <emilin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 15:28:43 by esimpson          #+#    #+#              #
#    Updated: 2024/03/26 13:27:31 by emilin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft
READLINE_PATH = /usr/local/opt/readline
BUILTINS_PATH = srcs/builtins
ENV_PATH = srcs/env
EXEC_PATH = srcs/execution

SRCS_PATH = srcs

LIBFT = $(LIBFT_PATH)/libft.a

INCLUDE = includes

SRC_FILES = $(SRCS_PATH)/minishell_main.c  $(SRCS_PATH)/free.c \
			$(ENV_PATH)/init_env.c  $(ENV_PATH)/utils_env.c \
			$(BUILTINS_PATH)/echo.c  $(BUILTINS_PATH)/env.c  $(BUILTINS_PATH)/exit.c \
			$(BUILTINS_PATH)/export.c $(BUILTINS_PATH)/pwd.c \
			$(EXEC_PATH)/test_cmd.c
 
SRC_OBJ = $(SRC_FILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRC_OBJ) 
	@make -C $(LIBFT_PATH) all
	@$(CC) $(CFLAGS) $(SRC_OBJ)  -o $(NAME) -I$(READLINE_PATH)/include -L$(READLINE_PATH)/lib -lreadline  -I$(INCLUDE) $(LIBFT)
	@echo "SUCCESSFULLY MADE $(words $(SRC_OBJ)) object files"

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -f $(SRC_OBJ) 

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME) 

re: fclean $(NAME) 

.PHONY:	all clean fclean re