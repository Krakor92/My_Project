/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** move_reset.c
*/

#include "utilsCSFML.h"

void move_index__reset(move_index_t *move)
{
	if (!move)
		return;
	sfClock_restart(move->chrono->clock);
	move->current = NULL;
	move->started = FALSE;
	move->finished = FALSE;
	move->active = FALSE;
}
