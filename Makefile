# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 15:13:23 by tbatteux          #+#    #+#              #
#    Updated: 2023/06/01 17:52:09 by tbatteux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror 

all: ${NAME}

${NAME}:
	gcc -o ${NAME} *.c ${FLAGS}

clean:

fclean: clean
	rm -f ${NAME}

re: fclean all 
