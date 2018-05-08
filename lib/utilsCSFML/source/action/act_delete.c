/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that delete or clean dlist
*/

#include "utilsCSFML.h"

void act__destroy(act_t *act)
{
	if (act->sound)
		sfMusic_destroy(act->sound);
	chrono__destroy(act->chrono);
	act_list_index__destroy_soft(act->dependencies);
	act_list_index__destroy_soft(act->interdictions);
	free(act);
	act = NULL;
}
