_END=\033[0m
_BOLD=\033[1m
_UNDER=\033[4m
_REV=\033[7m

_GREY=\033[30m
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


NAME = libft.a

CC = clang
CFLAGS = -Wall -Wextra -Werror -fno-builtin -O3

MAKE = make --no-print-directory

HEADER = libft.h

OBJS = $(SRCS:%.c=%.o)
SRCS = $(wildcard src/*.c)

%.o: %.c $(HEADER)
	@printf "[ ${_PURPLE}${_BOLD}${NAME}${_END} ] > [ $(_GREEN)$(_BOLD)+$(_END) ][ compiling ] $(_BLUE)$(_BOLD)$<$(_END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@printf "[ ${_PURPLE}${_BOLD}${NAME}${_END} ] > [ $(_GREEN)$(_BOLD)+$(_END) ][ building ] $(_BLUE)$(_BOLD)$(NAME)$(_END)\n"
	@$(AR) rcs $(NAME) $(OBJS)
	@printf "[ ${_PURPLE}${_BOLD}${NAME}${_END} ] > [ $(_BLUE)$(_BOLD)!$(_END) ][ done ]\n"

re: fclean
	@$(MAKE) all

clean:
	@$(RM) $(OBJS)
	@printf "[ ${_PURPLE}${_BOLD}${NAME}${_END} ] > [ $(_RED)$(_BOLD)-$(_END) ][ removing ] $(_BLUE)$(_BOLD)libft objs $(_END)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "[ ${_PURPLE}${_BOLD}${NAME}${_END} ] > [ $(_RED)$(_BOLD)-$(_END) ][ removing ] $(_BLUE)$(_BOLD)$(NAME) $(_END)\n"

norm:
	@norminettev2

.PHONY: all re clean fclean norm