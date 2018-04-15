/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** chrono.c
*/

#include "utilsCSFML.h"

chrono_t *chrono__malloc(void)
{
	chrono_t *chrono = NULL;

	chrono = malloc(sizeof(*chrono));
	if (!chrono)
		return my_ptr_error(INVALID_MALLOC);
	chrono->name = NULL;
	chrono->clock = NULL;
	chrono->restart_action = NULL;
	chrono->update= NULL;
	return chrono;
}

chrono_t *chrono__create(double restart, void (*restart_action)(void),
			bool_t (*update)(chrono_t*))
{
	chrono_t *chrono = NULL;

	chrono = chrono__malloc();
	if (!chrono)
		return NULL;
	chrono->clock = sfClock_create();
	chrono->restart = restart;
	chrono->update= update;
	chrono->restart_action = restart_action;
	return chrono;
}

void chrono__destroy(chrono_t *chrono)
{
	sfClock_destroy(chrono->clock);
	free(chrono);
	chrono = NULL;
}

bool_t chrono__update(chrono_t *chrono)
{
	chrono->time = sfClock_getElapsedTime(chrono->clock);
	chrono->elapsed = chrono->time.microseconds/1000000.0;
	if (chrono->elapsed >= chrono->restart) {
		if (chrono->restart_action)
			chrono->restart_action();
		sfClock_restart(chrono->clock);
		return TRUE;
	}
	return FALSE;
}

bool_t chrono__update2(chrono_t *chrono, double mult)
{
	chrono->time = sfClock_getElapsedTime(chrono->clock);
	chrono->elapsed = chrono->time.microseconds/1000000.0;
	if (chrono->elapsed >= (chrono->restart * mult)) {
		if (chrono->restart_action)
			chrono->restart_action();
		sfClock_restart(chrono->clock);
		return TRUE;
	}
	return FALSE;
}
