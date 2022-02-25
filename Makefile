NAME=push_swap
CC=gcc
FLAGS=-Wall -Werror -Wextra -g
SRCS=main.c \
		checks.c \
		utils.c \
		utils_2.c \
		ops.c \
		ops_2.c \
		ops_3.c \
		ops_utils.c \
		sort.c \
		sort_utils.c \
		values.c \
		find.c \
		decide.c \
		treat.c

OBJS=$(SRCS:.c=.o)
LIBPRINTF=./includes/libftprintf.a


$(NAME): $(OBJS) $(LIBPRINTF)
	$(CC) $(FLAGS) $(SRCS) $(LIBPRINTF) -o $(NAME)

all: $(NAME)

clean:
	rm -f *.o
	$(MAKE) clean -C ./includes

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./includes

re: fclean all

$(LIBPRINTF):
	$(MAKE) -C ./includes/

.PHONY: all clean fclean re
