##
## EPITECH PROJECT, 2017
## [N/A]
## File description:
## My_printf lib's Makefile
##

CC	=	gcc

RM	=	rm -f

CPPFLAGS	+=	-I$(HDRDIR)
CFLAGS	+=	-Wall -Wextra -ansi -pedantic -std=c99
LFLAGS	=

SRCDIR	=	source/
HDRDIR	=	include/

SRC	=	$(SRCDIR)base_converter_flags.c	\
		$(SRCDIR)base_converter.c	\
		$(SRCDIR)basic_flags.c	\
		$(SRCDIR)my_printf.c	\
		$(SRCDIR)specific_flags.c

OBJ	=	$(SRC:%.c=%.o)

HDR	=	$(HDRDIR)basic_c.h	\
		$(HDRDIR)my_printf.h

LIB	=	lib$(LIBNAME).a

LIBNAME =	my_printf



all:	$(LIB)

$(LIB):	$(OBJ) $(HDR)
	ar -rc $@ $(OBJ)
	ranlib $@

%.o: %.c $(HDR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIB)

re:	fclean all

debug:	CFLAGS += -g3
debug:	re

.PHONY:	all clean fclean re debug
