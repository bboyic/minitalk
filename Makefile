# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 16:32:01 by aconchit          #+#    #+#              #
#    Updated: 2021/11/19 16:57:18 by aconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server/server
NAME1 = client/client
CC = gcc -Wall -Wextra -Werror
C_FILE = server/server.c utils.c
C_FILE1 = client/client.c utils.c 
O_FILE = $(C_FILE:.c=.o)
O_FILE1 = $(C_FILE1:.c=.o)
HEADER = main.h

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@ -I ./

all: $(NAME) $(NAME1)

$(NAME): $(O_FILE)
	$(CC) $(O_FILE) -o $@

$(NAME1): $(O_FILE1)
	$(CC) $(O_FILE1) -o $@ -I ./

clean:
	rm -rf $(O_FILE) $(O_FILE1)

fclean: clean
	rm -rf $(NAME) $(NAME1)

re: fclean all

.PHONY: all clean fclean re