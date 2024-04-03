# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 09:17:19 by pdeson            #+#    #+#              #
#    Updated: 2024/02/27 09:20:02 by pdeson           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_malloc
PRINT_PREFIX    =	\033[1m\033[38;5;240m[\033[0m\033[38;5;250m\
                   		 $(NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m

CC				=	@cc
CFLAGS    =	-Wall -Werror -Wextra -g3

SRC_DIR   =	srces/
OBJ_DIR   =	.obj/

SRC       =	main.c ft_utils.c ft_malloc.c ft_free.c ft_free_all.c \
            ft_lst0.c ft_lst1.c ft_lst2.c

SRCES           =	$(addprefix $(SRC_DIR), $(SRC))
OBJ             =	$(SRC:.c=.o)
OBJS            =	$(addprefix $(OBJ_DIR), $(OBJ))

NUM_FILES		=	$(words $(SRCES))
BAR_LENGTH		=	$(shell echo "$$(($(NUM_FILES)*2))")

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@printf "$(PRINT_PREFIX)\033[0;38;5;226m Compiling \033[0m["
	@for i in $(shell seq 1 $(BAR_LENGTH)); do \
		sleep 0.1; \
		printf "\033[38;5;40m▲▼"; \
	done
	@printf "\033[38;5;40m] \033[0m\n"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(PRINT_PREFIX)\033[0;32m Done \033[0;37m\n"

clean:
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Cleaning \033[0m\n"
	@rm -rf $(OBJS)
	@echo "$(PRINT_PREFIX)\033[0;32m Done \033[0;37m\n"

fclean: clean
	@rm -rf $(NAME) $(OBJ_DIR)

re: fclean all

run: all clean
	./$(NAME)

.PHONY: all clean fclean re run
