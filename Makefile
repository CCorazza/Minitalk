# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/09 14:02:51 by ccorazza          #+#    #+#              #
#    Updated: 2014/02/09 17:39:23 by ccorazza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= serveur

NAME2		= client

LIB			= libft/

CLIENT		= clients/client.c	\

SERVER		= servers/server.c	\
			  servers/load.c	\

LIB			= libft/libft.a

CLIENTS		= $(CLIENT:.c=.o)

SERVERS		= $(SERVER:.c=.o)

CC			= @gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= @rm -rf

all:		$(NAME)

$(NAME): $(CLIENTS) $(SERVERS)
	@echo "\033[1;36m"
	@echo "__________________________________________________________________ "
	@echo "|     _____  .__       .__  __         .__   __                   |"
	@echo "|    /     \ |__| ____ |__|/  |______  |  | |  | __        _      |"
	@echo "|   /  \ /  \|  |/    \|  \   __\__  \ |  | |  |/ /      _( )_    |"
	@echo "|  /    Y    \  |   |  \  ||  |  / __ \|  |_|    <      (_ o _)   |"
	@echo "|  \____|__  /__|___|  /__||__| (____  /____/__|_ \      (_,_)    |"
	@echo "|          \/        \/              \/          \/               |"
	@echo "|_________________________________________________________________|"
	@make -C libft
	@$(CC) -o $(NAME) $(SERVER) $(CFLAGS) $(LIB)
	@$(CC) -o $(NAME2) $(CLIENT) $(CFLAGS) $(LIB)

clean:
	@make -C libft/ clean
	@$(RM) $(CLIENTS) $(SERVERS)
	@echo "\033[1;32mClean \033[1;35m √"

fclean:		clean
	@make -C libft/ fclean
	@$(RM) $(NAME)
	@$(RM) $(NAME2)
	@echo "\033[1;32mFclean \033[1;35m √"

re:			fclean $(NAME)

.PHONY : fclean clean all
