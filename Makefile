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

CC	=	gcc

RM	=	rm -f

# compiling flags here
CFLAGS	=	-W -Wall -Wextra -ansi -pedantic -g3 -std=c99 -I$(HDRDIR)
# linking flags here
LFLAGS	=	-lgcov

# library flags here
LDFLAGS	= -L$(LIBDIR)my_printf/ -L$(LIBDIR)utilsCSFML/ -L$(LIBDIR)basic_c/
LDLIBS	= -lc_graph_prog -lmy_printf -lutilsCSFML -lbasic_c

# directories location here
SRCDIR	=	source/
HDRDIR	=	include/
LIBDIR	=	lib/
UTDIR	=	tests/

SRC	=	$(SRCDIR)oldProject/get_next_line.c	\
		$(SRCDIR)dlist/str_dlist/delete_dlist.c	\
		$(SRCDIR)dlist/str_dlist/double_str_list.c	\
		$(SRCDIR)dlist/str_dlist/insert_n_get_str_dlist.c	\
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



all:	$(NAME)

$(NAME): $(OBJ) $(HDR)
	$(MAKE) -C $(LIBDIR)basic_c
	$(MAKE) -C $(LIBDIR)my_printf
	$(MAKE) -C $(LIBDIR)utilsCSFML
	@echo "============================"
	@echo -e "||\e[34m SUCCESSFUL COMPILATION \e[0m||"
	@echo "============================"
	$(CC) -o $@ $(OBJ) $(LFLAGS) $(LDFLAGS) $(LDLIBS)
	@echo "======================"
	@echo -e "||\e[32m LINKING COMPLETE \e[0m||"
	@echo "======================"
	@echo -e "\e[95m\n=> \e[1m"$@"\e[21m has been created!\n\e[0m"

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -o $@ -c $<

tests_run:
	@echo "======================="
	@echo -e "||\e[33m LAUNCH UNIT_TESTS \e[0m||"
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
	@echo -e "||\e[31m BINARY + LIBS + OBJ_FILES DELETED \e[0m||"
	@echo "======================================="

re:	fclean all

.PHONY: all tests_run clean fclean re
