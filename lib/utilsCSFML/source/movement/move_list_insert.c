/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions whose are related to the head and tail of dlists
*/

#include "utilsCSFML.h"

int move_list_index__insert_node_tail(move_list_index_t *index,
					move_list_node_t *node)
{
	if (!index || !node)
		return my_int_error("Insertion aborted!\n");
	if (move_list_index__is_empty(index)) {
		index->head = node;
		index->tail = node;
		index->nb_moves = 1;
	}
	else {
		index->tail->prev = node;
		node->next = index->tail;
		index->tail = node;
		index->nb_moves++;
	}
	return 0;
}

int move_list_index__insert_node_head(move_list_index_t *index,
					move_list_node_t *node)
{
	if (!index || !node)
		return my_int_error("Insertion aborted!\n");
	if (move_list_index__is_empty(index)) {
		index->head = node;
		index->tail = node;
		index->nb_moves = 1;
	}
	else {
		index->head->next = node;
		node->prev = index->head;
		index->head = node;
		index->nb_moves++;
	}
	return 0;
}

int move_list_index__insert_new_node_tail(move_list_index_t *index,
						move_index_t *move)
{
	move_list_node_t *new_node = NULL;

	new_node = move_list_node__create(move);
	if (!new_node)
		return -1;
	if (move_list_index__insert_node_tail(index, new_node) == -1)
		return -1;
	return 0;
}

int move_list_index__insert_new_node_head(move_list_index_t *index,
						move_index_t *move)
{
	move_list_node_t *new_node = NULL;

	new_node = move_list_node__create(move);
	if (!new_node)
		return -1;
	if (move_list_index__insert_node_head(index, new_node) == -1)
		return -1;
	return 0;
}
