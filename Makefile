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
## $< -> Représente la première dépendance
##
## lib: c_graph_prog (CSFML), m (math), ncurses (<-)...
##
## SI VOUS COPIEZ CE DOSSIER POUR UN PROJET, VOUS DEVEZ:
## - Retirer ou Ajouter des fichiers à compiler (.c ou .h)
## - Changer le $(NAME) du binaire
## - Changer le nom du header my_project.h avec votre nom de projet
## - Ajouter ou retirer des librairies
## - Changer le contenu de my_project.h en fonction des fonctions retirées
## - Faire de même dans le dossier $(UT_DIR)
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra -pedantic -g3 -std=c99 -I include/

LDFLAGS	+=	-L$(LIB_DIR)my_printf/
LDFLAGS	+=	-L$(LIB_DIR)utilsCSFML/
LDFLAGS	+=	-L$(LIB_DIR)utils1/

LDLIBS	+=	-lc_graph_prog -lutilsCSFML -lmy_printf -lutils1

HDR_DIR	=	include/
LIB_DIR	=	lib/
SRC_DIR	=	source/
UT_DIR	=	tests/

SRC	=	$(SRC_DIR)oldProject/get_next_line.c	\
		$(SRC_DIR)dlist/str_dlist/delete_dlist.c	\
		$(SRC_DIR)dlist/str_dlist/double_str_list.c	\
		$(SRC_DIR)dlist/str_dlist/insert_n_get_str_dlist.c	\
		$(SRC_DIR)utils2/2d_arrays/create_2d_arr.c	\
		$(SRC_DIR)utils2/2d_arrays/destroy_2d_arr.c	\
		$(SRC_DIR)utils2/file/copy_file_in_str.c	\
		$(SRC_DIR)utils2/str_manip/str_realloc.c	\
		$(SRC_DIR)main.c

OBJ	=	$(SRC:.c=.o)

HDR	=	$(HDR_DIR)get_next_line.h	\
		$(HDR_DIR)str_dlist.h	\
		$(HDR_DIR)my_printf.h	\
		$(HDR_DIR)my_project.h	\
		$(HDR_DIR)utils1.h	\
		$(HDR_DIR)utils2.h	\
		$(HDR_DIR)utilsCSFML.h

NAME	=	exe



all:	$(NAME)

$(NAME):	lib $(OBJ) $(HDR)
	$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)

lib:
	$(MAKE) -C $(LIB_DIR)utils1
	$(MAKE) -C $(LIB_DIR)my_printf
	$(MAKE) -C $(LIB_DIR)utilsCSFML

tests_run:
	$(MAKE) -C $(UT_DIR)

clean:
	$(RM) $(OBJ)
	./mr_clean

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all lib clean fclean re
