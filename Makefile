NAME		:= libftprintf.a

SRC_DIR		:= ./src/
INC_DIR		:= ./include/
INT_DIR		:= ./obj/

OBJ_FILES	:=

all: $(NAME)

$(NAME):

bonus:

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)