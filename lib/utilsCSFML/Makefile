##
## EPITECH PROJECT, 2017
## [N/A]
## File description:
## utilsCSFML lib's Makefile
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra -ansi -pedantic -g3 -std=c99 -I include/
LFLAGS	+=

SRCDIR	=	source/
HDRDIR	=	include/
LIBDIR	=	../

SRC	=	$(SRCDIR)create_2d_sfVector.c	\
		$(SRCDIR)create_my_window.c	\
		$(SRCDIR)create_sfRect.c	\
		$(SRCDIR)handle_events.c

OBJ	=	$(SRC:%.c=%.o)

HDR	=	$(HDRDIR)basic_c.h	\
		$(HDRDIR)utilsCSFML.h

LIB	=	lib$(LIBNAME).a

LIBNAME =	utilsCSFML



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
