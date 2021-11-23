NAME = libmini.a

SRC = ft_putendl.c	ft_error.c	ft_isdigit.c	ft_atoi.c

OBJ = $(patsubst %.c,%.o,$(SRC))

HEADER = libmini.h

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
		ar rcs $(NAME) $?

%.o: %.c
		gcc $(CFLAGS) -c $<

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

norm:
		norminette $(SRC) $(HEADER)

.PHONY: clean fclean re norm all
