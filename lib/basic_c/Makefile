##
## EPITECH PROJECT, 2017
## [N/A]
## File description:
## Basic_c lib's Makefile
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra -ansi -pedantic -g3 -std=c99 -I$(HDRDIR)
LFLAGS	=

SRCDIR	=	source/
HDRDIR	=	include/

SRC	=	$(SRCDIR)my_char_count.c	\
		$(SRCDIR)my_checkchar.c	\
		$(SRCDIR)my_checkstr.c	\
		$(SRCDIR)my_getnbr.c	\
		$(SRCDIR)my_getnchar_id.c	\
		$(SRCDIR)my_int_error.c	\
		$(SRCDIR)my_nbrlen.c	\
		$(SRCDIR)my_nlinelen.c	\
		$(SRCDIR)my_ptr_error.c	\
		$(SRCDIR)my_putchar.c	\
		$(SRCDIR)my_putnbr.c	\
		$(SRCDIR)my_putstr_error.c	\
		$(SRCDIR)my_putstr.c	\
		$(SRCDIR)my_putunbr.c	\
		$(SRCDIR)my_strcpy.c	\
		$(SRCDIR)my_strdup.c	\
		$(SRCDIR)my_strequal.c	\
		$(SRCDIR)my_strlen.c	\
		$(SRCDIR)my_strmodif.c	\
		$(SRCDIR)my_strncpy.c	\
		$(SRCDIR)my_unbrlen.c

OBJ	=	$(SRC:%.c=%.o)

HDR	=	$(HDRDIR)basic_c.h

LIB	=	lib$(LIBNAME).a

LIBNAME =	basic_c



all:	$(LIB)

$(LIB):	$(OBJ) $(HDR)
	ar -rc $@ $(OBJ)
	ranlib $@

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIB)

re:	fclean $(LIB)

.PHONY:	all clean fclean re
