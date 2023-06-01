# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 15:13:23 by tbatteux          #+#    #+#              #
#    Updated: 2023/05/30 15:29:58 by tbatteux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$NAME = push_swap
$FLAGS = -Wall -Wextra -Werror 

all: ${NAME}

${NAME}:
	gcc -o ${NAME} *.c ${FLAGS}

clean:
	rm -f ${NAME}

fclean: clean

re: fclean all 
