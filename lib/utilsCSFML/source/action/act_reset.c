/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** act_reset.c
*/

#include "utilsCSFML.h"

void act__reset(act_t *act)
{
	if (!act)
		return;
	if (act->sound)
		sfMusic_stop(act->sound);
	if (act->chrono)
		sfClock_restart(act->chrono->clock);
	act->on_hold = FALSE;
	act->active = FALSE;
	act->started = FALSE;
//	act->finished = FALSE;
	anim_index__reset(act->anim);
	move_index__reset(act->move);
}
