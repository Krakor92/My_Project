##
## EPITECH PROJECT, 2017
## [N/A]
## File description:
## utilsCSFML lib's Makefile
##

RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra -pedantic -g3 -std=c99 -I include/

HDR_DIR	=	include/
SRC_DIR	=	source/
LIB_DIR	=	../

SRC	=	$(SRC_DIR)create_2d_sfVector.c	\
		$(SRC_DIR)create_my_window.c	\
		$(SRC_DIR)create_sfRect.c	\
		$(SRC_DIR)handle_events.c

OBJ	=	$(SRC:.c=.o)

HDR	=	$(HDR_DIR)utils1.h	\
		$(HDR_DIR)utilsCSFML.h

LIBNAME =	utilsCSFML

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
