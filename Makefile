
NAME = libftprintf.a

CC = cc
CPPFLAGS = -I.
CFLAGS = -Wall -Wextra -Werror

SRCS =

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

