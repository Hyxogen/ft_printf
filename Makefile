NAME		:= libftprintf.a

SRC_DIR		:= ./src
INC_DIR		:= ./include
INT_DIR		:= ./obj
DEPEND		:= $(INC_DIR)/ft_printf.h

VPATH		:= $(SRC_DIR) $(SRC_DIR)/format $(SRC_DIR)/utils

SRC_FILES	:= $(SRC_DIR)/ft_printf.c $(SRC_DIR)/format_info.c \
				$(SRC_DIR)/format_info_utils.c $(SRC_DIR)/format/format_char.c $(SRC_DIR)/dispatcher.c \
				$(SRC_DIR)/format/format_specifier.c $(SRC_DIR)/format/format_string.c $(SRC_DIR)/utils/char_utils.c \
				$(SRC_DIR)/utils/number_utils.c $(SRC_DIR)/utils/string_utils.c $(SRC_DIR)/format/format_sint.c \
				$(SRC_DIR)/format/format_hex.c $(SRC_DIR)/format/format_hex_utils.c $(SRC_DIR)/format/format_int_utils.c \
				$(SRC_DIR)/format/format_uint.c $(SRC_DIR)/format/format_pointer.c $(SRC_DIR)/utils/padding_utils.c \
				$(SRC_DIR)/utils/ft_atoi.c $(SRC_DIR)/utils/ft_isdigit.c $(SRC_DIR)/utils/ft_memchr.c $(SRC_DIR)/utils/ft_memset.c \
				$(SRC_DIR)/utils/ft_strchr.c $(SRC_DIR)/utils/ft_strlen.c $(SRC_DIR)/utils/ft_strncmp.c $(SRC_DIR)/utils/ft_isspace.c
OBJ_FILES	:= $(SRC_FILES:$(SRC_DIR)/%.c=$(INT_DIR)/%.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -I $(INC_DIR) 
# -fsanitize=address

all: distribution

bonus: all

SILENT		:= @
ifdef VERBOSE
SILENT		:=
endif

$(NAME): $(NAME)($(notdir $(OBJ_FILES)))
	$(SILENT)echo Creating $(NAME)

$(NAME)(%.o): $(INT_DIR)/%.o
	$(SILENT)ar rcs $(NAME) $<

$(INT_DIR)/%.o: %.c
	$(SILENT)mkdir -p $(INT_DIR)
	$(SILENT)echo $(notdir $<)
	$(SILENT)$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(SILENT)echo Cleaning object files
	$(SILENT)(cd $(INT_DIR) && rm -f $(notdir $(OBJ_FILES)))

fclean: clean
	$(SILENT)echo Cleaning $(NAME)
	$(SILENT)rm -f $(NAME)

re: fclean all

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
.PRECIOUS: $(INT_DIR)/%.o