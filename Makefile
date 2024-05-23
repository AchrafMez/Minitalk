NAME = client
NAME_BONUS = client_bonus
NAME_2 = server
NAME_BONUS_2 = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
	
OBJC = mandatory/client.c
OBJS = mandatory/server.c
OBJCb = bonus/client_bonus.c
OBJSb = bonus/server_bonus.c
HEDER = mandatory/minitalk.h
HEDER_B = bonus/minitalk_bonus.h

all: $(NAME_2) $(NAME)

$(NAME_2): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	
$(NAME): $(OBJC) $(HEDER)
	@$(CC) $(CFLAGS) $(OBJC) -o $@
	
bonus: $(NAME_BONUS) $(NAME_BONUS_2)

$(NAME_BONUS): $(OBJCb) $(HEDER_B)
	@$(CC) $(CFLAGS) $(OBJCb) -o $@

$(NAME_BONUS_2): $(OBJSb) $(HEDER_B)
	@$(CC) $(CFLAGS) $(OBJSb) -o $@

clean:
	$(RM) $(NAME) $(NAME_2) $(NAME_BONUS) $(NAME_BONUS_2)

fclean: clean

re: fclean all
