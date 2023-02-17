NAME = client 

NAME_2 = server

CLIENT_BONUS = client_bonus

SERVER_BONUS = server_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRCS_CLIENT = libft_nedeed.c\
							client.c

SRCS_SERVER = libft_nedeed.c\
							server.c

SRCS_BONUS_CLIENT = libft_nedeed_bonus.c\
										client_bonus.c

SRCS_BONUS_SERVER = libft_nedeed_bonus.c\
										server_bonus.c


OBJ_CLIENT = ${SRCS_CLIENT:.c=.o}

OBJ_SERVER = ${SRCS_SERVER:.c=.o}

OBJ_BONUS_CLIENT = ${SRCS_BONUS_CLIENT:.c=.o}

OBJ_BONUS_SERVER = ${SRCS_BONUS_SERVER:.c=.o}

all : $(NAME) $(NAME_2)

bonus : $(CLIENT_BONUS) $(SERVER_BONUS)

$(NAME) : $(OBJ_CLIENT) 
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_2) : $(OBJ_SERVER)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_BONUS) : $(OBJ_BONUS_CLIENT)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER_BONUS) : $(OBJ_BONUS_SERVER)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_BONUS_CLIENT) $(OBJ_BONUS_SERVER)

fclean : clean
	$(RM) $(NAME) $(NAME_2) $(CLIENT_BONUS) $(SERVER_BONUS)

re : fclean all
