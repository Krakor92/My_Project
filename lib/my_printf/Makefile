##
## EPITECH PROJECT, 2017
## [N/A]
## File description:
## My_printf lib's Makefile
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra -ansi -pedantic -g3 -std=c99 -I$(HDRDIR)
LFLAGS	=

SRCDIR	=	source/
HDRDIR	=	include/
LIBDIR	=	../

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
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIB)

re:	fclean $(LIB)

.PHONY:	all clean fclean re
