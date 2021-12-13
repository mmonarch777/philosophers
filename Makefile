NAME = philo

SRC = main.c	ft_init.c	dinner.c	utils.c

OBJ = $(patsubst %.c,%.o,$(SRC))

HEADER = philo.h

LIBMINI_DIR = libmini

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(LIBMINI_DIR)
		make -C $(LIBMINI_DIR)
		gcc $(OBJ) -L$(LIBMINI_DIR) -lmini -o $(NAME)

%.o: %.c
		gcc $(CFLAGS) -c $<

clean:
		make clean -C $(LIBMINI_DIR)
		rm -f $(OBJ)

fclean: clean
		make fclean -C $(LIBMINI_DIR)
		rm -f $(NAME)

re: fclean all

norm:
		make norm -C $(LIBMINI_DIR)
		norminette $(SRC) $(HEADER)

.PHONY: all clean fclean re norm