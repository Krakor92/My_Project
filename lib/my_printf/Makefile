##
## EPITECH PROJECT, 2017
## [N/A]
## File description:
## My_printf lib's Makefile
##

RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra -pedantic -g3 -std=c99 -I include/

HDR_DIR	=	include/
SRC_DIR	=	source/
LIB_DIR	=	../

SRC	=	$(SRC_DIR)base_converter_flags.c	\
		$(SRC_DIR)base_converter.c	\
		$(SRC_DIR)basic_flags.c	\
		$(SRC_DIR)my_printf.c	\
		$(SRC_DIR)specific_flags.c

OBJ	=	$(SRC:.c=.o)

HDR	=	$(HDR_DIR)basic_c.h	\
		$(HDR_DIR)my_printf.h

LIBNAME =	my_printf

LIB	=	lib$(LIBNAME).a



all:	$(LIB)

$(LIB):	$(OBJ) $(HDR)
	ar -rc $@ $^
	ranlib $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIB)

re:	fclean $(LIB)

.PHONY:	all clean fclean re
