NAME = philo

CC = gcc
CFLAGS = -Werror -Wextra -Wall -g

HEADER = ./includes/philo.h

SRCS =  ./philo.c \
		./srcs/act_eat.c \
		./srcs/act_sleep.c \
		./srcs/act_think.c \
		./srcs/babelf.c \
		./srcs/get_time.c \
		./srcs/msg_display.c \
		./srcs/philosopher.c \
		./srcs/precise_usleep.c \
		./srcs/room_services.c \

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) $(OBJS) -o $(NAME)

.PHONY: all clean fclean re

all:	$(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all
