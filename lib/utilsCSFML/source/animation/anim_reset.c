/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** anim_reset.c
*/

#include "utilsCSFML.h"

void anim_index__reset(anim_index_t *anim)
{
	if (!anim)
		return;
	sfClock_restart(anim->chrono->clock);
	anim->current = NULL;
	anim->started = FALSE;
	anim->finished = FALSE;
}
