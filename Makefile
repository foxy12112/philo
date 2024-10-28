# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldick <ldick@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 17:52:31 by ldick             #+#    #+#              #
#    Updated: 2024/10/28 13:45:22 by ldick            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

#################################################################################################
#											Colors												#
#################################################################################################

CLR_RMV		:= \033[0m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
BOLD_BLUE	:= \033[0;34m
NC			:= \033[0m

#################################################################################################
#											Flags												#
#################################################################################################

COMPILER	=	cc
INCLUDES	=	-I includes -I main-libs
SUBMODULE	=	main-libs/Makefile
CFLAGS		=	-pthread -Wall -Werror -Wextra
ERROR_FILE	=	error.log

#################################################################################################
#											Sources												#
#################################################################################################

_UTILS		=	init.c print.c time.c utils.c error.c eaat.c routine.c
UTILS		=	$(addprefix utils/, $(_UTILS))

_SRCS		=	main.c $(UTILS)
SRCS		=	$(addprefix srcs/, $(_SRCS))

OBJS		=	$(SRCS:srcs/%.c=bin/%.o)
LIBRARY		=	main-libs/libs.a

#################################################################################################
#											Rules												#
#################################################################################################

all:			$(NAME)

bin:
				@echo "\t\t\t$(BLUE) Making bin directory"
				@echo "\t\t\t$(BOLD_BLUE) mkdir -p bin/utils"
				@mkdir -p bin/utils

bin/%.o:		srcs/%.c | bin
				@echo "$(GREEN) Compiling $(Compiler) $(CLR_RMV) -c -o $(YELLOW) $@ $(CYAN) $^ $(GREEN) $(CFLAGS) $(GREEN) $(INCLUDES) $(NC)"
				@$(COMPILER) -c -o $@ $^ $(CFLAGS) $(INCLUDES) 2> $(ERROR_FILE) || (cat $(ERROR_FILE) && echo "$(RED)Compilation failed :0\nfailed file: \t\t$(YELLOW)$<$(NC)\n\n" && exit 1)

$(NAME):		$(OBJS)
				@$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS)
				@echo "\t\t\t\t$(RED) compilation success :3"

clean:
				@rm -rf bin
				@rm -f $(ERROR_FILE)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re