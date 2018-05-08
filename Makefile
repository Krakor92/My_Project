##
## EPITECH PROJECT, 2017
## [N/A] {Vincent FAIVRE}
## File description:
## My compilation's Makefile
##
## Variables génériques:
## $? -> Liste des dépendances qui ont été modifiées
## $^ -> Liste de toutes les dépendances
## (ces dernières doivent contenir les chemins vers leurs fichiers)
## $+ -> Comme au dessus mais les doublons sont supprimés
## $@ -> La cible courante (cible de la règle où on se trouve)
## $< -> Représente la première dépendance(bug avec $(OBJ))
##
## Tips:
## Retirer -g3 pour le push final
## Rajouter @ devant une commande la rends "muette"
## lib: c_graph_prog (CSFML), m (math), ncurses (<-)...
##

SHELL	=	/bin/sh

CC	=	gcc

RM	=	rm -f

DEBUG	=	yes

# compiling flags here (-pg => optimiser le programme + gprof ./exe (sans les args et après avoir executer))
CPPFLAGS	+=	-W -Wall -Wextra -I$(HDRDIR)
CFLAGS	=	-ansi -pedantic -std=c99
# linking flags here
LFLAGS	=	-lgcov

# library flags here
LDFLAGS	= -L$(LIBDIR)my_printf/ -L$(LIBDIR)utilsCSFML/ -L$(LIBDIR)basic_c/
LDLIBS	= -lc_graph_prog -lmy_printf -lutilsCSFML -lbasic_c

LIBRULE	=

# directories location here
SRCDIR	=	source/
HDRDIR	=	include/
LIBDIR	=	lib/
UTDIR	=	tests/

SRC	=	$(SRCDIR)dlist/str_dlist/delete_dlist.c	\
		$(SRCDIR)dlist/str_dlist/double_str_list.c	\
		$(SRCDIR)dlist/str_dlist/insert_n_get_str_dlist.c	\
		$(SRCDIR)my_math/float_compar.c	\
		$(SRCDIR)my_math/line_intersection.c	\
		$(SRCDIR)oldProject/get_next_line.c	\
		$(SRCDIR)main.c

OBJ	=	$(SRC:%.c=%.o)

HDR	=	$(HDRDIR)basic_c.h	\
		$(HDRDIR)get_next_line.h	\
		$(HDRDIR)str_dlist.h	\
		$(HDRDIR)my_printf.h	\
		$(HDRDIR)my_project.h	\
		$(HDRDIR)my_structs.h	\
		$(HDRDIR)utilsCSFML.h

# project name (generate executable with this name)
NAME	=	exe



ifeq ($(DEBUG), yes)
	LIBRULE = debug
	CFLAGS += -g3
endif



all:	$(NAME)

$(NAME): $(OBJ) $(HDR)
ifeq ($(DEBUG), yes)
	@echo "==========================="
	@echo -e "||\e[96m LAUNCH DEBUGGING MODE \e[0m||"
	@echo "==========================="
endif
	$(MAKE) -C $(LIBDIR)basic_c $(LIBRULE)
	$(MAKE) -C $(LIBDIR)my_printf $(LIBRULE)
	$(MAKE) -C $(LIBDIR)utilsCSFML $(LIBRULE)
	@echo "============================"
	@echo -e "||\e[94m SUCCESSFUL COMPILATION \e[0m||"
	@echo "============================"
	$(CC) -o $@ $(OBJ) $(LFLAGS) $(LDFLAGS) $(LDLIBS)
	@echo "======================"
	@echo -e "||\e[92m LINKING COMPLETE \e[0m||"
	@echo "======================"
	@echo -e "\e[95m\n=> \e[1m"$@"\e[21m has been created!\n\e[0m"

%.o: %.c $(HDR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<

tests_run:
	@echo "======================="
	@echo -e "||\e[93m LAUNCH UNIT_TESTS \e[0m||"
	@echo "======================="
	$(MAKE) -C $(UTDIR)

clean:
	$(RM) $(OBJ)

fclean:	 clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBDIR)basic_c fclean
	$(MAKE) -C $(LIBDIR)my_printf fclean
	$(MAKE) -C $(LIBDIR)utilsCSFML fclean
	$(MAKE) -C $(UTDIR) fclean
	./mr_clean
	@echo "======================================="
	@echo -e "||\e[91m BINARY + LIBS + OBJ_FILES DELETED \e[0m||"
	@echo "======================================="

re:	fclean all

debug:	LIBRULE = debug
debug:	CFLAGS += -g3
debug:	re

.PHONY: all tests_run clean fclean re debug
