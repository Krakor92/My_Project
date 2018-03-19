##
## EPITECH PROJECT, 2017
## [N/A]
## File description:
## Utils1 lib's Makefile
##

RM	=	rm -f

CFLAGS	+=	-I include/

SRC_DIR	=	source/
HDR_DIR	=	include/

SRC	=	$(SRC_DIR)my_char_count.c	\
		$(SRC_DIR)my_checkchar.c	\
		$(SRC_DIR)my_checkstr.c	\
		$(SRC_DIR)my_getnbr.c	\
		$(SRC_DIR)my_getnchar_id.c	\
		$(SRC_DIR)my_int_error.c	\
		$(SRC_DIR)my_nbrlen.c	\
		$(SRC_DIR)my_nlinelen.c	\
		$(SRC_DIR)my_ptr_error.c	\
		$(SRC_DIR)my_putchar.c	\
		$(SRC_DIR)my_putnbr.c	\
		$(SRC_DIR)my_putstr_error.c	\
		$(SRC_DIR)my_putstr.c	\
		$(SRC_DIR)my_putunbr.c	\
		$(SRC_DIR)my_strcpy.c	\
		$(SRC_DIR)my_strdup.c	\
		$(SRC_DIR)my_strequal.c	\
		$(SRC_DIR)my_strlen.c	\
		$(SRC_DIR)my_strmodif.c	\
		$(SRC_DIR)my_strncpy.c	\
		$(SRC_DIR)my_unbrlen.c

OBJ	=	$(SRC:.c=.o)

HDR	=	$(HDR_DIR)basic_c.h

LIBNAME =	basic_c

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
