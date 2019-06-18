##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## make the palindrome exe
##

SRCDIR	=	src

SRC	=	$(wildcard $(SRCDIR)/*.c) \
		$(wildcard $(SRCDIR)/get/*.c) \
		$(wildcard $(SRCDIR)/utils/*.c) \
		$(wildcard $(SRCDIR)/display/*.c) \
		$(wildcard $(SRCDIR)/execut_func/*.c)


OBJ	=	$(SRC:.c=.o)

CFLAGS =	-I ./include -g -Wall -W

NAME	=	projTester

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean $(NAME) clean

.PHONY: all clean fclean re
