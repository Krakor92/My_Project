##
## EPITECH PROJECT, 2017
## [N/A] {Vincent FAIVRE}
## File description:
## My test's  Makefile
##
## WARNING: Criterion uses its own main(void);
## Having a main() in any .c file will have the build fail
##
CC	=	gcc

CFLAGS	+=	-W -Wall -Wextra -pedantic -g3 -std=c99 -I ../include/

LDFLAGS	+=	-lcriterion -lgcov --coverage

SRC_DIR	=	../source/
SRC_UT_DIR	=	./

SRC	=	$(SRC_DIR)str_dlist/delete_dlist.c	\
		$(SRC_DIR)str_dlist/double_str_list.c	\
		$(SRC_DIR)str_dlist/insert_n_get_str_dlist.c	\
		$(SRC_DIR)utils1/my_char_count.c	\
		$(SRC_DIR)utils1/my_getnbr.c	\
		$(SRC_DIR)utils1/my_int_error.c	\
		$(SRC_DIR)utils1/my_nbrlen.c	\
		$(SRC_DIR)utils1/my_ptr_error.c	\
		$(SRC_DIR)utils1/my_putchar.c	\
		$(SRC_DIR)utils1/my_putnbr.c	\
		$(SRC_DIR)utils1/my_putstr_error.c	\
		$(SRC_DIR)utils1/my_putstr.c	\
		$(SRC_DIR)utils1/my_putunbr.c	\
		$(SRC_DIR)utils1/my_strcpy.c	\
		$(SRC_DIR)utils1/my_strdup.c	\
		$(SRC_DIR)utils1/my_strequal.c	\
		$(SRC_DIR)utils1/my_strlen.c	\
		$(SRC_DIR)utils1/my_strncpy.c	\
		$(SRC_DIR)utils1/my_unbrlen.c	\
		$(SRC_DIR)utils2/2d_arrays/create_2d_arr.c	\
		$(SRC_DIR)utils2/2d_arrays/destroy_2d_arr.c	\
		$(SRC_DIR)utilsCSFML/create_2d_sfVector.c	\
		$(SRC_DIR)utilsCSFML/create_my_window.c	\
		$(SRC_DIR)utilsCSFML/create_sfRect.c

SRC_UT	=	$(SRC_UT_DIR)unit_tests.c

OBJ	=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

NAME	=	test



all:	tests

tests:	$(NAME) $(OBJ)
	-./$(NAME) --verbose

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	.././mr_clean

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all tests clean fclean re
