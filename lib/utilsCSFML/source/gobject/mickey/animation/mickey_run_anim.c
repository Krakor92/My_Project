/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** mickey_run_anim.c
*/

#include "utilsCSFML.h"

anim_index_t *mickey__create_run_anim(sfTexture *ttr)
{
	anim_index_t *running = NULL;
	chrono_t *chrono = NULL;
	int retval = 0;

	chrono = chrono__create(0.12, NULL, chrono__update);
	running = anim_index__create("run", ttr, chrono, TRUE);
	if (!running)
		return NULL;
	retval += anim_index__insert_new_node_end(running,
		(sfIntRect){0, 41, 40, 40}, (sfIntRect){4, 0, 31, 40}, 1);
	retval += anim_index__insert_new_node_end(running,
		(sfIntRect){41, 41, 40, 40}, (sfIntRect){3, 2, 35, 38}, 1);
	retval += anim_index__insert_new_node_end(running,
		(sfIntRect){82, 41, 40, 40}, (sfIntRect){6, 3, 27, 37}, 1);
	retval += anim_index__insert_new_node_end(running,
		(sfIntRect){123, 41, 40, 40}, (sfIntRect){5, 2, 29, 38}, 1);
	retval += anim_index__insert_new_node_end(running,
		(sfIntRect){164, 41, 40, 40}, (sfIntRect){3, 2, 35, 38}, 1);
	retval += anim_index__insert_new_node_end(running,
		(sfIntRect){205, 41, 40, 40}, (sfIntRect){8, 3, 26, 37}, 1);
	if (retval < 0)
		return NULL;
	return running;
}
