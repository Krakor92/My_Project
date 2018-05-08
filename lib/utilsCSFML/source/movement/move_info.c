/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that are relative to the basics of double linked lists
*/

#include "utilsCSFML.h"

move_info_t *move_info__malloc(void)
{
	move_info_t *info = NULL;

	info = malloc(sizeof(*info));
	if (!info)
		return my_ptr_error(INVALID_MALLOC);
	info->type = FIXED;
	info->loop_type = SINGLE_LOOP;
	return info;
}

move_info_t *move_info__create(move_type_t type, move_loop_type_t loop_type)
{
	move_info_t *info = NULL;

	info = move_info__malloc();
	if (!info)
		return NULL;
	info->type = type;
	info->loop_type = loop_type;
	return info;
}

void move_info__destroy(move_info_t *info)
{
	free(info);
	info = NULL;
}
