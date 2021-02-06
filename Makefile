_END=\033[0m
_BOLD=\033[1m
_UNDER=\033[4m
_REV=\033[7m

_RED=\033[31m
_GREEN=\033[32m
_YELLOW=\033[33m
_BLUE=\033[34m
_PURPLE=\033[35m
_CYAN=\033[36m
_WHITE=\033[37m

_IGREY=\033[40m
_IRED=\033[41m
_IGREEN=\033[42m
_IYELLOW=\033[43m
_IBLUE=\033[44m
_IPURPLE=\033[45m
_ICYAN=\033[46m
_IWHITE=\033[47m

NAME = miniRT

CC = clang
CFLAGS = -Wall -Wextra -Werror -fno-builtin -g
MAKE = make --no-print-directory
RECOMPILE_MLX = 0

ifeq ($(shell uname -s),Linux)
MLX = -I/usr/include -L/usr/lib -lX11 -lmlx -lXext -lm -lpthread
endif
ifeq ($(shell uname -s),Darwin)
MLX= -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

HEADER = \
	includes/minirt.h \

OBJS = $(SRCS:%.c=%.o)
SRCS = \
	src/vectors/vectors1.c \
	src/vectors/vectors2.c \
	src/init/engine_config.c \
	src/parsing/parsing.c \
	src/parsing/get_objects1.c \
	src/minirt.c \
	src/utils.c \
	src/colors.c \
	src/camera.c \
	src/engine_events.c \
	src/frame_control.c \
	
%.o: %.c $(HEADER)
	@printf "[ $(_GREEN)$(_BOLD)>+$(_END) ][ compiling ] $(_BLUE)$(_BOLD)$<$(_END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME}

mlx:
ifeq ($(shell uname -s),Darwin)
	@$(MAKE) -C ./mlx
	@cp ./mlx/libmlx.dylib .
endif

$(NAME) : $(OBJS)
	@$(MAKE) -C ./libft
	@$(MAKE) mlx
	@printf "[ $(_GREEN)$(_BOLD)>+$(_END) ][ building ] $(_BLUE)$(_BOLD)$(NAME)$(_END)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a $(MLX)
	@printf "[ $(_GREEN)$(_BOLD):)$(_END) ][ done ] $(_BLUE)$(_BOLD)$(NAME)$(_END)\n"

clean:
	@$(MAKE) clean -C ./libft
	@printf "[ $(_RED)$(_BOLD)--$(_END) ][ removing ] $(_BLUE)$(_BOLD)printf objs $(_END)\n"
	@$(RM) $(OBJS)

fclean: clean
ifeq ($(RECOMPILE_MLX), 1)
	@$(MAKE) clean -C ./mlx
endif
	@$(MAKE) fclean -C ./libft
	@$(RM) libmlx.dylib
	@printf "[ $(_RED)$(_BOLD)--$(_END) ][ removing ] $(_BLUE)$(_BOLD)$(NAME) $(_END)\n"
	@$(RM) $(NAME)	
	@find . -name "*.bmp" -delete -print
	@find . -name "*.out" -delete -print

re: fclean
	@$(MAKE) all

soft: 
	@$(MAKE) all 
	@$(MAKE) -C libft 
	@printf "[ $(_GREEN)$(_BOLD)>+$(_END) ][ building ] $(_BLUE)$(_BOLD)$(NAME)$(_END)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a $(MLX)
	@printf "[ $(_GREEN)$(_BOLD):)$(_END) ][ done ] $(_BLUE)$(_BOLD)$(NAME)$(_END)\n"

norm:
	@$(MAKE) norm -C ./libft
	norminette src/*.[ch] includes/*.[ch]

leaks: soft
ifeq ($(shell uname -s),Linux)
	valgrind -- ./$(NAME) ./scenes/test.rt --save
endif
ifeq ($(shell uname -s),Darwin)
	leaks --atExit -- ./$(NAME) ./scenes/test.rt --save
endif

test: soft
	./$(NAME) ./scenes/test.rt

save: soft
	./$(NAME) ./scenes/test.rt --save
	# open ./save.bmp

.PHONY: all mlx clean fclean re soft norm leaks test save