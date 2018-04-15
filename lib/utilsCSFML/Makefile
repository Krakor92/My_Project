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

SRC	=	$(SRCDIR)animation/anim_delete.c	\
		$(SRCDIR)animation/anim_insert.c	\
		$(SRCDIR)animation/anim_list_delete.c	\
		$(SRCDIR)animation/anim_list_insert.c	\
		$(SRCDIR)animation/anim_list_manip.c	\
		$(SRCDIR)animation/anim_list.c	\
		$(SRCDIR)animation/anim_test.c	\
		$(SRCDIR)animation/anim.c	\
		$(SRCDIR)animation/animation.c	\
		$(SRCDIR)events/handle_events.c	\
		$(SRCDIR)events/key_events.c	\
		$(SRCDIR)events/mouse_events.c	\
		$(SRCDIR)events/window_events.c	\
		$(SRCDIR)chrono.c	\
		$(SRCDIR)create_my_window.c	\
		$(SRCDIR)display.c	\
		$(SRCDIR)gobject_list.c	\
		$(SRCDIR)gobject.c	\
		$(SRCDIR)launch_csfml.c	\
		$(SRCDIR)sfRect.c	\
		$(SRCDIR)sfRenderStates.c	\
		$(SRCDIR)sfVector2d.c

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
