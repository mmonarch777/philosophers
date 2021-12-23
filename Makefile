NAME = philo
NAME_BONUS = philo_bonus

SRC =	mandatory/main.c\
		mandatory/ft_init.c\
		mandatory/dinner.c\
		mandatory/utils.c

SRC_BONUS =	bonus/main_bonus.c\
			bonus/go_eat.c\
			bonus/utils_bonus.c

OBJ = $(patsubst %.c,%.o,$(SRC))
OBJ_BONUS = $(patsubst %.c,%.o,$(SRC_BONUS))

HEADER = mandatory/philo.h
HEADER_BONUS = bonus/philo_bonus.h

LIBMINI_DIR = libmini

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(LIBMINI_DIR)
		make -C $(LIBMINI_DIR)
		gcc $(OBJ) -L$(LIBMINI_DIR) -lmini -o $(NAME)

%.o: %.c
		gcc $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(HEADER_BONUS) $(LIBMINI_DIR)
		make -C $(LIBMINI_DIR)
		gcc $(OBJ_BONUS) -L$(LIBMINI_DIR) -lmini -o $(NAME_BONUS)

clean:
		make clean -C $(LIBMINI_DIR)
		rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
		make fclean -C $(LIBMINI_DIR)
		rm -f $(NAME) $(NAME_BONUS)

re: fclean all

norm:
		make norm -C $(LIBMINI_DIR)
		norminette $(SRC) $(HEADER) $(SRC_BONUS) $(HEADER_BONUS)

.PHONY: all clean fclean re norm bonus