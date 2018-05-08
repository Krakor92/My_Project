/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that are relative to the basics of double linked lists
*/

#include "utilsCSFML.h"

move_list_index_t *move_list_index__malloc(void)
{
	move_list_index_t *index = NULL;

	index = malloc(sizeof(*index));
	if (!index)
		return my_ptr_error(INVALID_MALLOC);
	index->nb_moves = 0;
	index->head = NULL;
	index->tail = NULL;
	return index;
}

move_list_index_t *move_list_index__create(void)
{
	move_list_index_t *index = NULL;

	index = move_list_index__malloc();
	if (!index)
		return NULL;
	return index;
}

move_list_node_t *move_list_node__malloc(void)
{
	move_list_node_t *node = NULL;

	node = malloc(sizeof(*node));
	if (!node)
		return my_ptr_error(INVALID_MALLOC);
	node->move = NULL;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

move_list_node_t *move_list_node__create(move_index_t *move)
{
	move_list_node_t *node = NULL;

	node = move_list_node__malloc();
	if (!node)
		return NULL;
	node->move = move;
	return node;
}

bool_t move_list_index__is_empty(move_list_index_t *index)
{
	if (index->nb_moves == 0 && !index->head && !index->tail)
		return TRUE;
	return FALSE;
}
