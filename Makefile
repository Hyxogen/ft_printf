NAME		:= libftprintf.a

SRC_DIR		:= ./src
INC_DIR		:= ./include
INT_DIR		:= ./obj
DEPEND		:= $(INC_DIR)/ft_printf.h

SRC_FILES	:= $(SRC_DIR)/ft_printf.c
OBJ_FILES	:= $(SRC_FILES:$(SRC_DIR)/%.c=$(INT_DIR)/%.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -I $(INC_DIR)

all: distribution

bonus:

$(NAME): $(OBJ_FILES)

$(NAME)(%.o): $(INT_DIR)/%.o
	ar rcs $(NAME) $<

$(INT_DIR)/%.o: $(SRC_DIR)/%.c
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
debug: $(NAME)

.PHONY: all bonus clean fclean re debug release distribution