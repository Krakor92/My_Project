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

LDFLAGS	+=	-L$(LIB_DIR)my_printf
LDFLAGS	+=	-L$(LIB_DIR)utilsCSFML
LDFLAGS	+=	-L$(LIB_DIR)utils1

LDLIBS	+=	-lc_graph_prog -lmy_printf -lutilsCSFML -lutils1
LDLIBS	+=	-lcriterion -lgcov --coverage

SRC_DIR	=	../source/
SRC_UT_DIR	=	./source/
LIB_DIR	=	../lib/
HDR_DIR	=	../include/

SRC	=	$(SRC_DIR)oldProject/get_next_line.c	\
		$(SRC_DIR)dlist/str_dlist/delete_dlist.c	\
		$(SRC_DIR)dlist/str_dlist/double_str_list.c	\
		$(SRC_DIR)dlist/str_dlist/insert_n_get_str_dlist.c	\
		$(SRC_DIR)utils2/2d_arrays/create_2d_arr.c	\
		$(SRC_DIR)utils2/2d_arrays/destroy_2d_arr.c

SRC_UT	=	$(SRC_UT_DIR)utils1_t1.c	\
		$(SRC_UT_DIR)utils1_t2.c	\
		$(SRC_UT_DIR)utils1_t3.c	\
		$(SRC_UT_DIR)utils1_t4.c

OBJ	=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

HDR	=	$(HDR_DIR)get_next_line.h	\
		$(HDR_DIR)str_dlist.h	\
		$(HDR_DIR)my_printf.h	\
		$(HDR_DIR)my_project.h	\
		$(HDR_DIR)utils1.h	\
		$(HDR_DIR)utils2.h	\
		$(HDR_DIR)utilsCSFML.h

NAME	=	test



all:	tests

tests:	$(NAME) $(OBJ)
	- ./$(NAME) --verbose

$(NAME):	lib $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

lib:
	$(MAKE) -C $(LIB_DIR)utils1
	$(MAKE) -C $(LIB_DIR)my_printf
	$(MAKE) -C $(LIB_DIR)utilsCSFML

clean:
	rm -f $(OBJ)
	.././mr_clean

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all tests lib clean fclean re
