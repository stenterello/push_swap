NAME=push_swap

CHECKERNAME=checker

CC=gcc

FLAGS=-Wall -Werror -Wextra -g

MAINSRC=src/main.c

CHECKERMAIN=src/checker.c

CHECKERSRC=src/checker_ops.c \
			src/checker_ops_2.c \
			src/checker_ops_3.c

SRCS=src/checks.c \
		src/checks_utils.c \
		src/utils.c \
		src/utils_2.c \
		src/ops.c \
		src/ops_2.c \
		src/ops_3.c \
		src/ops_utils.c \
		src/sort.c \
		src/sort_utils.c \
		src/values.c \
		src/find.c \
		src/decide.c \
		src/treat.c \
		src/seq.c \
		src/seq_utils.c

OBJS=$(SRCS:.c=.o)
MAINOBJ=$(MAINSRC:.c=.o)
CHECKEROBJS=$(CHECKERSRC:.c=.o)
CHECKERMAINOBJ=$(CHECKERMAIN:.c=.o)

LIBPRINTF=./includes/libftprintf.a

$(NAME): $(OBJS) $(LIBPRINTF) src/main.o
	$(CC) $(FLAGS) $(MAINSRC) $(SRCS) $(LIBPRINTF) -o $(NAME)	

$(LIBPRINTF):
	$(MAKE) -C ./includes/

all: $(NAME)

$(CHECKERNAME): $(OBJS) $(CHECKEROBJS) $(CHECKERMAINOBJ) $(LIBPRINTF)
	$(CC) $(FLAGS) $(CHECKERMAINOBJ) $(CHECKEROBJS) $(OBJS) $(LIBPRINTF) -o $(CHECKERNAME)

clean:
	rm -f src/*.o
	$(MAKE) clean -C ./includes

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKERNAME)
	$(MAKE) fclean -C ./includes

bonus: $(CHECKERNAME)

re: fclean all

.PHONY: all clean fclean bonus re
