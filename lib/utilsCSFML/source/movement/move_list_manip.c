/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that are relative to the basics of double linked lists
*/

#include "utilsCSFML.h"

move_index_t *move_list_index__find_move_index(move_list_index_t *index,
						char *name)
{
	move_list_node_t *node = NULL;

	if (!index || !name)
		return NULL;
	for (node = index->tail; node; node = node->next) {
		if (my_strequal(name, node->move->name))
			return node->move;
	}
	return NULL;
}


void move_list_index__reset_move_index(move_list_index_t *index,
					char *name)
{
	move_index_t *move = NULL;

	if (!index || !name)
		return;
	move = move_list_index__find_move_index(index, name);
	move_index__reset(move);
}
