##
## EPITECH PROJECT, 2017
## [N/A]
## File description:
## utilsCSFML lib's Makefile
##

CC	=	gcc

RM	=	rm -f

CPPFLAGS	+=	-I$(HDRDIR) -I../../include/
CFLAGS	+=	-Wall -Wextra -ansi -pedantic -std=c99
LFLAGS	+=

SRCDIR	=	source/
HDRDIR	=	include/

SRC	=	$(SRCDIR)action/act_delete.c	\
		$(SRCDIR)action/act_list_delete.c	\
		$(SRCDIR)action/act_list_insert.c	\
		$(SRCDIR)action/act_list_manip.c	\
		$(SRCDIR)action/act_list.c	\
		$(SRCDIR)action/act_reset.c	\
		$(SRCDIR)action/act.c	\
		$(SRCDIR)action/action.c	\
		$(SRCDIR)animation/anim_delete.c	\
		$(SRCDIR)animation/anim_insert.c	\
		$(SRCDIR)animation/anim_list_delete.c	\
		$(SRCDIR)animation/anim_list_insert.c	\
		$(SRCDIR)animation/anim_list_manip.c	\
		$(SRCDIR)animation/anim_list.c	\
		$(SRCDIR)animation/anim_reset.c	\
		$(SRCDIR)animation/anim.c	\
		$(SRCDIR)animation/animation.c	\
		$(SRCDIR)collision/rect_collision.c	\
		$(SRCDIR)events/compare_events.c	\
		$(SRCDIR)events/handle_events.c	\
		$(SRCDIR)events/key_events.c	\
		$(SRCDIR)events/mouse_events.c	\
		$(SRCDIR)events/window_events.c	\
		$(SRCDIR)gobject/mickey/action/mickey_action.c	\
		$(SRCDIR)gobject/mickey/action/mickey_hide_act.c	\
		$(SRCDIR)gobject/mickey/action/mickey_idle_act.c	\
		$(SRCDIR)gobject/mickey/action/mickey_jump_act.c	\
		$(SRCDIR)gobject/mickey/action/mickey_run_left_act.c	\
		$(SRCDIR)gobject/mickey/action/mickey_run_right_act.c	\
		$(SRCDIR)gobject/mickey/action/mickey_stop_run_left_act.c	\
		$(SRCDIR)gobject/mickey/action/mickey_stop_run_right_act.c	\
		$(SRCDIR)gobject/mickey/animation/mickey_idle_anim.c	\
		$(SRCDIR)gobject/mickey/animation/mickey_jump_anim.c	\
		$(SRCDIR)gobject/mickey/animation/mickey_run_anim.c	\
		$(SRCDIR)gobject/mickey/movement/mickey_jump_move.c	\
		$(SRCDIR)gobject/mickey/movement/mickey_run_left_move.c	\
		$(SRCDIR)gobject/mickey/movement/mickey_run_right_move.c	\
		$(SRCDIR)gobject/mickey/movement/mickey_stop_run_left_move.c	\
		$(SRCDIR)gobject/mickey/movement/mickey_stop_run_right_move.c	\
		$(SRCDIR)gobject/mickey/mickey.c	\
		$(SRCDIR)gobject/gobject_collision.c	\
		$(SRCDIR)gobject/gobject.c	\
		$(SRCDIR)gobject_list/gobject_list.c	\
		$(SRCDIR)movement/move_delete.c	\
		$(SRCDIR)movement/move_info.c	\
		$(SRCDIR)movement/move_insert.c	\
		$(SRCDIR)movement/move_list_delete.c	\
		$(SRCDIR)movement/move_list_insert.c	\
		$(SRCDIR)movement/move_list_manip.c	\
		$(SRCDIR)movement/move_list.c	\
		$(SRCDIR)movement/move_reset.c	\
		$(SRCDIR)movement/move.c	\
		$(SRCDIR)movement/movement.c	\
		$(SRCDIR)chrono.c	\
		$(SRCDIR)create_my_window.c	\
		$(SRCDIR)display.c	\
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
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIB)

re:	fclean all

debug:	CFLAGS += -g3
debug:	re

.PHONY:	all clean fclean re debug
