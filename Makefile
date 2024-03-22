# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 04:14:29 by ybouyzem          #+#    #+#              #
#    Updated: 2024/03/09 04:41:17 by ybouyzem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_CLIENT = client.c minitalk_utils.c \

C_SERVER = server.c minitalk_utils.c \

OBJS_C = $(C_CLIENT:.c=.o)
OBJS_S = $(C_SERVER:.c=.o)

NAME_C = client
NAME_S = server

all : client server

client : $(C_CLIENT) $(OBJS)
	cc -Wall -Wextra -Werror $(C_CLIENT) -o client
server : $(C_SERVER) $(OBJS)
	cc -Wall -Wextra -Werror $(C_SERVER) -o server

%.o : %.c minitalk.h
	cc -Wall -Wextra -Werror -c $< -o $@

clean :
	rm -f $(OBJS_C) $(OBJS_S) 

fclean : clean
	rm -f $(NAME_C) $(NAME_S)

re : fclean all

.PHONY : all clean fclean re