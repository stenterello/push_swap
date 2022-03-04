NAME=push_swap

CHECKERNAME=checker

CC=gcc

FLAGS=-Wall -Werror -Wextra

MAINSRC=main.c

CHECKERMAIN=checker.c

CHECKERSRC=checker_ops.c \
			checker_ops_2.c \
			checker_ops_3.c

SRCS=checks.c \
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
		treat.c \
		seq.c \
		seq_utils.c

OBJS=$(SRCS:.c=.o)
MAINOBJ=$(MAINSRC:.c=.o)
CHECKEROBJS=$(CHECKERSRC:.c=.o)
CHECKERMAINOBJ=$(CHECKERMAIN:.c=.o)

LIBPRINTF=./includes/libftprintf.a

$(NAME): $(OBJS) $(LIBPRINTF) main.o
	$(CC) $(FLAGS) $(MAINOBJ) $(OBJS) $(LIBPRINTF) -o $(NAME)	

$(LIBPRINTF):
	$(MAKE) -C ./includes/

all: $(NAME)

$(CHECKERNAME): $(OBJS) $(CHECKEROBJS) $(CHECKERMAINOBJ) $(LIBPRINTF)
	$(CC) $(FLAGS) $(CHECKERMAINOBJ) $(CHECKEROBJS) $(OBJS) $(LIBPRINTF) -o $(CHECKERNAME)

clean:
	rm -f *.o
	$(MAKE) clean -C ./includes

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKERNAME)
	$(MAKE) fclean -C ./includes

bonus: $(CHECKERNAME)

re: fclean all

.PHONY: all clean fclean bonus re
