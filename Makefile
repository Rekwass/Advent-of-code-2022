SRC			=	main.c 						\
				day1/calorieCounting.cpp

RM 			= 	rm -f

CC 			= 	g++

OBJ			=	$(SRC:.c=.o)

NAME		=	adventOfCode2022

CPPFLAGS	=	-I./include/

CFLAGS		=	-Wall -Wextra

all: 	lib $(NAME)

$(NAME): 	$(OBJ)
	$(LINK.o) -o $@ $^ $(LDLIBS)

debug: CFLAGS += -g
debug: fclean all

clean:
	$(RM) $(OBJ)

fclean: 	clean
	$(RM) $(NAME)

re: 	fclean all

.PHONY: all lib debug clean fclean re