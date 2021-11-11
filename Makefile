NAME		:= libftprintf.a

SRC_DIR		:= ./src
INC_DIR		:= ./include
INT_DIR		:= ./obj
LIBFT_DIR	:= ./Dependencies/Libft
DEPEND		:= $(INC_DIR)/ft_printf.h

VPATH		:= $(SRC_DIR) $(SRC_DIR)/format

SRC_FILES	:= $(SRC_DIR)/ft_printf.c $(SRC_DIR)/format_info.c $(SRC_DIR)/ft_printf_utils.c $(SRC_DIR)/debug_utils.c \
				$(SRC_DIR)/format_info_utils.c $(SRC_DIR)/format/format_char.c $(SRC_DIR)/dispatcher.c \
				$(SRC_DIR)/format/format_specifier.c
OBJ_FILES	:= $(SRC_FILES:$(SRC_DIR)/%.c=$(INT_DIR)/%.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -I $(INC_DIR) -fsanitize=address

all: distribution

bonus:

test: debug
	cc -fsanitize=address $(NAME) $(LIBFT_DIR)/libft.a src/main.c
	./a.out

$(NAME): $(NAME)($(notdir $(OBJ_FILES)))

$(NAME)(%.o): $(INT_DIR)/%.o
	ar rcs $(NAME) $<

$(INT_DIR)/%.o: %.c
	@mkdir -p $(INT_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

debug: CFLAGS += -O0 -g -DDEBUG
debug: TARGET := debug
debug: $(NAME)

release: CFLAGS += -O2 -DRELEASE
release: TARGET := release
release: $(NAME)

distribution: CFLAGS += -Ofast -DDISTRIBUTION
distribution: TARGET := distribution
distribution: $(NAME)

.PHONY: all bonus clean fclean re debug release distribution
.PRECIOUS: $(OBJ_FILES)