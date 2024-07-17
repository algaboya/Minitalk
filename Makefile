# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algaboya <algaboya@student.42yerevan.am    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 15:05:07 by algaboya          #+#    #+#              #
#    Updated: 2024/07/16 15:20:17 by algaboya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SRCSS = server.c
SRCSC  = client.c

OBJSS = $(SRCSS:%.c=%.o)
OBJSC = $(SRCSC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJSS)
	cc $(CFLAGS) $(OBJSS) -o $(SERVER)

$(CLIENT): $(OBJSC)
	cc $(CFLAGS) $(OBJSC) -o $(CLIENT)

clean:
	rm -rf $(OBJSC) $(OBJSS)

fclean:
	rm -rf $(OBJSC) $(OBJSS) $(SERVER) $(CLIENT)

re: fclean all

.PHONY : all clean fclean re