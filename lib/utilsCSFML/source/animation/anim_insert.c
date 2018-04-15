/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions whose are related to the head and tail of dlists
*/

#include "utilsCSFML.h"

int anim_index__insert_node_start(anim_index_t *index, anim_node_t *node)
{
	if (!index || !node)
		return my_int_error("Insertion aborted!\n");
	if (anim_index__is_empty(index)) {
		index->start = node;
		index->end = node;
		index->nb_frames = 1;
	}
	else {
		index->start->prev = node;
		node->next = index->start;
		index->start = node;
		index->nb_frames++;
	}
	if (index->loop) {
		index->start->prev = index->end;
		index->end->next = index->start;
	}
	return 0;
}

int anim_index__insert_node_end(anim_index_t *index, anim_node_t *node)
{
	if (!index || !node)
		return my_int_error("Insertion aborted!\n");
	if (anim_index__is_empty(index)) {
		index->start = node;
		index->end = node;
		index->nb_frames = 1;
	}
	else {
		index->end->next = node;
		node->prev = index->end;
		index->end = node;
		index->nb_frames++;
	}
	if (index->loop) {
		index->end->next = index->start;
		index->start->prev = index->end;
	}
	return 0;
}

int anim_index__insert_new_node_start(anim_index_t *index,
					 sfIntRect rect,
					    double on)
{
	anim_node_t *new_node = NULL;

	new_node = anim_node__create(rect, on);
	if (!new_node)
		return -1;
	if (anim_index__insert_node_start(index, new_node) == -1)
		return -1;
	return 0;
}

int anim_index__insert_new_node_end(anim_index_t *index,
				       sfIntRect rect,
					  double on)
{
	anim_node_t *new_node = NULL;

	new_node = anim_node__create(rect, on);
	if (!new_node)
		return -1;
	if (anim_index__insert_node_end(index, new_node) == -1)
		return -1;
	return 0;
}
