# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 18:52:16 by kgeorgia          #+#    #+#              #
#    Updated: 2021/11/21 19:26:27 by kgeorgia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			web_serv

CC =			clang++

FLAGS =			-Wall -Wextra -Werror -g

RM =			rm -rf

DIR_HEADERS =	./includes/

DIR_LIBFT	=	./libft/

DIR_SRCS =		./srcs/

DIR_OBJS =		./objs/

LIBFT	=		./libft/libft.a

SRC =			main.cpp\
				server/Server.cpp\
				response/Response.cpp


SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

OBJS =			$(SRCS:.c=.o)

OBJS_2 =		$(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.cpp=.o))

all:			$(NAME)

$(NAME) :		$(OBJS_2)
				@$(CC) $(FLAGS) -I $(DIR_SRCS) $(OBJS_2) -o $(NAME)
				@echo "Compiled "$(NAME)" successfully!"

$(DIR_OBJS)%.o: $(DIR_SRCS)%.cpp
				@$(CC) $(FLAGS) -c $< -o $@
				@echo "Compiled "$<" successfully!"

norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)

clean:
				$(RM) $(OBJS_2)
				make -C ./libft/ clean

fclean:			clean
				make -C ./libft/ fclean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus