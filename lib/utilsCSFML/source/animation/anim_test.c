/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** launch_csfml.c
*/

#include "utilsCSFML.h"



anim_index_t *create_mickey_idle_anim(sfTexture *ttr)
{
	anim_index_t *idle = NULL;
	chrono_t *chrono = NULL;
	int retval = 0;

	chrono = chrono__create(0.15, NULL, chrono__update);
	idle = anim_index__create("idle", ttr, chrono, TRUE);
	if (!idle)
		return NULL;
	retval += anim_index__insert_new_node_end(idle, (sfIntRect){0, 0, 24, 40}, 1.5);
	retval += anim_index__insert_new_node_end(idle, (sfIntRect){25, 0, 24, 40}, 1);
	retval += anim_index__insert_new_node_end(idle, (sfIntRect){50, 0, 24, 40}, 1);
	retval += anim_index__insert_new_node_end(idle, (sfIntRect){75, 0, 24, 40}, 1);
	if (retval < 0)
		return NULL;
	return idle;
}

anim_index_t *create_mickey_running_anim(sfTexture *ttr)
{
	anim_index_t *running = NULL;
	chrono_t *chrono = NULL;
	int retval = 0;

	chrono = chrono__create(0.15, NULL, chrono__update);
	running = anim_index__create("running", ttr, chrono, TRUE);
	if (!running)
		return NULL;
	retval += anim_index__insert_new_node_end(running, (sfIntRect){0, 41, 35, 40}, 1);
	retval += anim_index__insert_new_node_end(running, (sfIntRect){36, 41, 35, 40}, 1);
	retval += anim_index__insert_new_node_end(running, (sfIntRect){72, 41, 35, 40}, 1);
	retval += anim_index__insert_new_node_end(running, (sfIntRect){108, 41, 35, 40}, 1);
	retval += anim_index__insert_new_node_end(running, (sfIntRect){144, 41, 35, 40}, 1);
	retval += anim_index__insert_new_node_end(running, (sfIntRect){180, 41, 35, 40}, 1);
	if (retval < 0)
		return NULL;
	return running;
}

anim_index_t *create_mickey_new_idle_anim(sfTexture *ttr)
{
	anim_index_t *idle = NULL;
	chrono_t *chrono = NULL;
	int retval = 0;

	chrono = chrono__create(0.15, NULL, chrono__update);
	idle = anim_index__create("idle", ttr, chrono, TRUE);
	if (!idle)
		return NULL;
	retval += anim_index__insert_new_node_end(idle, (sfIntRect){0, 0, 40, 40}, 1.5);
	retval += anim_index__insert_new_node_end(idle, (sfIntRect){41, 0, 40, 40}, 1);
	retval += anim_index__insert_new_node_end(idle, (sfIntRect){82, 0, 40, 40}, 1);
	retval += anim_index__insert_new_node_end(idle, (sfIntRect){123, 0, 40, 40}, 1);
	if (retval < 0)
		return NULL;
	return idle;
}

anim_index_t *create_mickey_new_running_anim(sfTexture *ttr)
{
	anim_index_t *running = NULL;
	chrono_t *chrono = NULL;
	int retval = 0;

	chrono = chrono__create(0.15, NULL, chrono__update);
	running = anim_index__create("running", ttr, chrono, TRUE);
	if (!running)
		return NULL;
	retval += anim_index__insert_new_node_end(running, (sfIntRect){0, 41, 40, 40}, 1);
	retval += anim_index__insert_new_node_end(running, (sfIntRect){41, 41, 40, 40}, 1);
	retval += anim_index__insert_new_node_end(running, (sfIntRect){82, 41, 40, 40}, 1);
	retval += anim_index__insert_new_node_end(running, (sfIntRect){123, 41, 40, 40}, 1);
	retval += anim_index__insert_new_node_end(running, (sfIntRect){164, 41, 40, 40}, 1);
	retval += anim_index__insert_new_node_end(running, (sfIntRect){205, 41, 40, 40}, 1);
	if (retval < 0)
		return NULL;
	return running;
}
