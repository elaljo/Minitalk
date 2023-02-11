CLIENT = client 

SERVER = server

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRCS = libft_nedeed.c

OBJ = ${SRCS:.c=.o}

all : $(CLIENT) $(SERVER)

$(CLIENT) : $(OBJ)
			$(CC) $(CFLAGS) client.c $< -o $@

$(SERVER) : $(OBJ)
			$(CC) $(CFLAGS) server.c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(CLIENT) $(SERVER)

re : all fclean