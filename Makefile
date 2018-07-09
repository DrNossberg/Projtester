##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## make the palindrome exe
##

SRCDIR	=	src

SRC	=	$(SRCDIR)/projTester.c \
		$(SRCDIR)/tree.c \
		$(SRCDIR)/display.c \
		$(SRCDIR)/parsing.c \
		$(SRCDIR)/fill_node_info.c \
		$(SRCDIR)/execute_tests.c \
		$(SRCDIR)/summary.c \
		$(SRCDIR)/utils/stradd.c \
		$(SRCDIR)/utils/mr_free.c \
		$(SRCDIR)/utils/cl_utils.c \
		$(SRCDIR)/utils/exec_utils.c \
		$(SRCDIR)/utils/add_slash.c \
		$(SRCDIR)/utils/str_to_word_array.c \
		$(SRCDIR)/execut_func/is_in_cd.c \
		$(SRCDIR)/execut_func/is_in_path.c \
		$(SRCDIR)/get/get_test_attributs.c \
		$(SRCDIR)/get/get_test_result.c \
		$(SRCDIR)/get/get_path.c

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

re:	fclean all

.PHONY: all clean fclean re
