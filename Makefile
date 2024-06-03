# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emilin <emilin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 15:28:43 by esimpson          #+#    #+#              #
#    Updated: 2024/06/03 12:25:39 by emilin           ###   ########.fr        #
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
TOKEN_PATH = srcs/tokenizer
PARSER_PATH = srcs/parsing
EXPANDER_PATH = srcs/expander
SIGNALS_PATH = srcs/signals

SRCS_PATH = srcs

LIBFT = $(LIBFT_PATH)/libft.a

INCLUDE = includes

SRC_FILES = $(SRCS_PATH)/minishell_main.c  $(SRCS_PATH)/free.c $(SRCS_PATH)/valid_utils.c \
			$(ENV_PATH)/init_env.c  $(ENV_PATH)/utils_env.c \
			$(BUILTINS_PATH)/cd.c $(BUILTINS_PATH)/echo.c  $(BUILTINS_PATH)/env.c  $(BUILTINS_PATH)/exit.c \
			$(BUILTINS_PATH)/export.c  $(BUILTINS_PATH)/unset.c $(BUILTINS_PATH)/pwd.c \
			$(TOKEN_PATH)/token_utils.c $(TOKEN_PATH)/tokenizer.c $(TOKEN_PATH)/token_append.c  \
			$(TOKEN_PATH)/token_list.c \
			$(PARSER_PATH)/parser.c  $(PARSER_PATH)/parser_error.c $(PARSER_PATH)/parser_nodes.c \
			$(PARSER_PATH)/parser_utils.c  $(PARSER_PATH)/parser_clear.c \
			$(EXPANDER_PATH)/expander.c $(EXPANDER_PATH)/expand_utils.c $(EXPANDER_PATH)/expander_split.c \
			$(EXPANDER_PATH)/clean_empty_strings.c $(EXPANDER_PATH)/strip_quotes.c $(EXPANDER_PATH)/heredoc_expander.c \
			$(EXEC_PATH)/execute.c  $(EXEC_PATH)/execute_builtin.c $(EXEC_PATH)/execute_simple_cmd.c \
			$(EXEC_PATH)/init_tree.c \
			$(SIGNALS_PATH)/signals.c \
 
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