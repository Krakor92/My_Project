/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** mickey_idle_anim.c
*/

#include "utilsCSFML.h"

anim_index_t *mickey__create_idle_anim(sfTexture *ttr)
{
	anim_index_t *idle = NULL;
	chrono_t *chrono = NULL;
	int retval = 0;

	chrono = chrono__create(0.15, NULL, chrono__update);
	idle = anim_index__create("idle", ttr, chrono, TRUE);
	if (!idle)
		return NULL;
	retval += anim_index__insert_new_node_end(idle,
		(sfIntRect){0, 0, 40, 40}, (sfIntRect){7, 0, 24, 40}, 1.5);
	retval += anim_index__insert_new_node_end(idle,
		(sfIntRect){41, 0, 40, 40}, (sfIntRect){7, 1, 24, 40}, 1);
	retval += anim_index__insert_new_node_end(idle,
		(sfIntRect){82, 0, 40, 40}, (sfIntRect){7, 2, 24, 40}, 1);
	retval += anim_index__insert_new_node_end(idle,
		(sfIntRect){123, 0, 40, 40}, (sfIntRect){7, 2, 24, 40}, 1);
	if (retval < 0)
		return NULL;
	return idle;
}
