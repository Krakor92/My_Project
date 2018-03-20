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
RM	=	rm -f

# compiling flags here
CFLAGS	=	-W -Wall -Wextra -ansi -pedantic -g3 -std=c99 -I$(HDRDIR)
CFLAGS	+=	--coverage
# linking flags here
LFLAGS	=	-lgcov

# library flags here
LDFLAGS	=	-L$(LIBDIR)my_printf/ -L$(LIBDIR)utilsCSFML/ -L$(LIBDIR)basic_c/
LDLIBS	=	-lc_graph_prog -lcriterion -lmy_printf -lutilsCSFML -lbasic_c

# directories location here
SRCDIR	=	../source/
UTSRCDIR=	source/
HDRDIR	=	../include/
LIBDIR	=	../lib/

SRC	=	$(SRCDIR)oldProject/get_next_line.c	\
		$(SRCDIR)dlist/str_dlist/delete_dlist.c	\
		$(SRCDIR)dlist/str_dlist/double_str_list.c	\
		$(SRCDIR)dlist/str_dlist/insert_n_get_str_dlist.c	\
		$(SRCDIR)utils2/2d_arrays/create_2d_arr.c	\
		$(SRCDIR)utils2/2d_arrays/destroy_2d_arr.c	\
		$(SRCDIR)utils2/file/copy_file_in_str.c	\
		$(SRCDIR)utils2/str_manip/str_realloc.c

UTSRC	=	$(UTSRCDIR)utils1/utils1_t1.c	\
		$(UTSRCDIR)utils1/utils1_t2.c	\
		$(UTSRCDIR)utils1/utils1_t3.c	\
		$(UTSRCDIR)utils1/utils1_t4.c	\
		$(UTSRCDIR)get_next_line/get_next_line_t1.c

OBJ	=	$(SRC:%c=%o) $(UTSRC:%c=%o)

HDR	=	$(HDRDIR)basic_c.h	\
		$(HDRDIR)get_next_line.h	\
		$(HDRDIR)str_dlist.h	\
		$(HDRDIR)my_printf.h	\
		$(HDRDIR)my_project.h	\
		$(HDRDIR)utils2.h	\
		$(HDRDIR)utilsCSFML.h

# project name (generate executable with this name)
NAME	=	utest



all:	tests

tests:	$(NAME) $(OBJ)
	./$(NAME)

valgrind:	$(NAME) $(OBJ)
	valgrind ./$(NAME)

$(NAME): lib $(OBJ)
	$(CC) -o $@ $(OBJ) $(LFLAGS) $(LDFLAGS) $(LDLIBS)

%.o: %.c $(HDR)
	$(CC) -o $@ -c $< $(CFLAGS)

lib:
	$(MAKE) -C $(LIBDIR)basic_c
	$(MAKE) -C $(LIBDIR)my_printf
	$(MAKE) -C $(LIBDIR)utilsCSFML

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all tests valgrind lib clean fclean re
