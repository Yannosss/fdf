##########   BASE   ##########
# File name
NAME = fdf

# Sources
SRCS += sources/bresenham.c
SRCS += sources/event_manager.c
SRCS += sources/event_fonctions_1.c
SRCS += sources/event_fonctions_2.c
SRCS += sources/exit.c
SRCS += sources/init.c
SRCS += sources/main.c
SRCS += sources/print_pixel.c
SRCS += sources/parsing_input_1.c
SRCS += sources/parsing_input_2.c
SRCS += sources/convert_coordinates.c
SRCS += sources/draw_grid.c

SRCS_BONUS += sources/bresenham.c
SRCS_BONUS += sources/event_manager_bonus.c
SRCS_BONUS += sources/event_fonctions_1.c
SRCS_BONUS += sources/event_fonctions_2.c
SRCS_BONUS += sources/exit.c
SRCS_BONUS += sources/init.c
SRCS_BONUS += sources/main.c
SRCS_BONUS += sources/print_pixel.c
SRCS_BONUS += sources/parsing_input_1.c
SRCS_BONUS += sources/parsing_input_2.c
SRCS_BONUS += sources/convert_coordinates.c
SRCS_BONUS += sources/draw_grid.c

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

HEADER += includes/fdf.h
HEADER += libft/libft.h

INCLUDES_DIR= -I ./includes -I ./libft/ -I ./minilibx-linux/

LIB_INCLUDE = -L ./libft -lft -L ./minilibx-linux/ -lmlx -lX11 -lXext -lm -lz

# Compilateurs
CC = gcc
#CFLAGS = -g
CFLAGS = -Wall -Wextra -Werror

##########   Cst mise en forme   ##########
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m

_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

##########   RULES   ##########
all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	make -C ./libft all
	${CC} ${OBJS} -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}

bonus: $(OBJS_BONUS) $(HEADER)
	make -C ./libft all
	${CC} ${OBJS_BONUS} -o ${NAME} ${CFLAGS} ${INCLUDES_DIR} ${LIB_INCLUDE}

%.o: %.c $(HEADER)
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES_DIR)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
