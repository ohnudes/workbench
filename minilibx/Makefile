
CC = cc -o -Wall -Wextra

NAME = program

SRC = main.c gettingstarted.c utils.c

OBJ = $(SRC:.c=.o)

DIR = ./INC/

LIB = $(DIR)/testing.h

--- 

all: $(NAME)

$(NAME):

$(OBJ):

%.o: %.c $(LIB) Makefile

clean: rm $(OBJ)

fclean:
	
re: clean all

# cool compilation
program: 

test:

.PHONY: re all clean fclean
