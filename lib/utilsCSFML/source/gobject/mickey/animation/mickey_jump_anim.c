/*
** EPITECH PROJECT, 2018
** [N/A] {Vincent FAIVRE}
** File description:
** mickey_jump_anim.c
*/

#include "utilsCSFML.h"

anim_index_t *mickey__create_jump_anim(sfTexture *ttr)
{
	anim_index_t *jump = NULL;
	chrono_t *chrono = NULL;
	int retval = 0;

	chrono = chrono__create(0.015, NULL, chrono__update);
	jump = anim_index__create("jump", ttr, chrono, TRUE);
	if (!jump)
		return NULL;
	retval += anim_index__insert_new_node_end(jump,
		(sfIntRect){0, 82, 40, 40}, (sfIntRect){1, 13, 38, 27}, 21);
	retval += anim_index__insert_new_node_end(jump,
		(sfIntRect){82, 82, 40, 40}, (sfIntRect){1, 13, 38, 27}, 21);
	if (retval < 0)
		return NULL;
	return jump;
}
