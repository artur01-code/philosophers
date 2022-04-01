# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 12:35:09 by jtomala           #+#    #+#              #
#    Updated: 2022/04/01 12:54:22 by jtomala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

SRC =	main.c \
		utils.c \
		actions.c \
		ft_atoi.c \
		check.c

OBJ = $(SRC:.c=.o) #we dont need it RAAAAAH

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re