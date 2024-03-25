# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouyzem <ybouyzem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 04:14:29 by ybouyzem          #+#    #+#              #
#    Updated: 2024/03/25 14:06:30 by ybouyzem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_CLIENT = client.c minitalk_utils.c \

C_SERVER = server.c minitalk_utils.c \

BONUS_CLIENT = bonus/client_bonus.c bonus/minitalk_utils_bonus.c \

BONUS_SERVER = bonus/server_bonus.c bonus/minitalk_utils_bonus.c \

OBJS_C = $(C_CLIENT:.c=.o)
OBJS_S = $(C_SERVER:.c=.o)

BONUS_OBJS_C = $(BONUS_CLIENT:.c=.o)
BONUS_OBJS_S = $(BONUS_SERVER:.c=.o)

NAME_C = client
NAME_S = server 

BONUS_C = client_bonus
BONUS_S = server_bonus

bonus/%.o : bonus/%.c bonus/minitalk_bonus.h
	cc -Wall -Wextra -Werror -c $< -o $@

%.o : %.c minitalk.h
	cc -Wall -Wextra -Werror -c $< -o $@

all : client server

client : $(OBJS_C)
	cc -Wall -Wextra -Werror $(OBJS_C) -o client
server : $(OBJS_S)
	cc -Wall -Wextra -Werror $(OBJS_S) -o server

bonus : client_bonus server_bonus

client_bonus : $(BONUS_OBJS_C) bonus/minitalk_bonus.h
	cc -Wall -Wextra -Werror $(BONUS_OBJS_C) -o $(BONUS_C)
server_bonus : $(BONUS_OBJS_S) bonus/minitalk_bonus.h
	cc -Wall -Wextra -Werror $(BONUS_OBJS_S) -o $(BONUS_S)

clean :
	rm -f $(OBJS_C) $(OBJS_S) $(BONUS_OBJS_C) $(BONUS_OBJS_S)

fclean : clean
	rm -f $(NAME_C) $(NAME_S) $(BONUS_C) $(BONUS_S)

re : fclean all

.PHONY : all clean fclean re