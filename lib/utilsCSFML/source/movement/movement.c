/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** gobject_move.c
*/

#include "utilsCSFML.h"

movement_t *movement__malloc(void)
{
	movement_t *movement = NULL;

	movement = malloc(sizeof(*movement));
	if (!movement)
		return my_ptr_error(INVALID_MALLOC);
	movement->chrono = NULL;
	movement->moves = NULL;
	return movement;
}

movement_t *movement__create(move_list_index_t *moves,
				chrono_t *chrono)
{
	movement_t *movement = NULL;

	if (!moves || !chrono)
		return NULL;
	movement = movement__malloc();
	if (!movement)
		return NULL;
	movement->moves = moves;
	movement->chrono = chrono;
	return movement;
}

void movement__destroy(movement_t *movement)
{
	if (!movement)
		return;
	chrono__destroy(movement->chrono);
	move_list_index__destroy(movement->moves);
	free(movement);
	movement = NULL;
}
