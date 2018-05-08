/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions whose are related to the head and tail of dlists
*/

#include "utilsCSFML.h"

void move_index__increase_by_one_all_node_number(move_index_t *index)
{
	move_node_t *node = NULL;

	if (!index)
		return;
	for (node = index->start; node; node = node->next)
		node->number++;
}

int move_index__insert_node_start(move_index_t *index, move_node_t *node)
{
	if (!index || !node)
		return my_int_error("Insertion aborted!\n");
	if (move_index__is_empty(index)) {
		index->start = node;
		index->end = node;
		index->nb_steps = 1;
	}
	else {
		index->start->prev = node;
		node->next = index->start;
		index->start = node;
		index->nb_steps++;
	}
	if (index->info && index->info->loop_type == INF_LOOP) {
		index->start->prev = index->end;
		index->end->next = index->start;
	}
	node->number = 0;
	move_index__increase_by_one_all_node_number(index);
	return 0;
}

int move_index__insert_node_end(move_index_t *index, move_node_t *node)
{
	if (!index || !node)
		return my_int_error("Insertion aborted!\n");
	if (move_index__is_empty(index)) {
		index->start = node;
		index->end = node;
		index->nb_steps = 1;
	}
	else {
		index->end->next = node;
		node->prev = index->end;
		index->end = node;
		index->nb_steps++;
	}
	if (index->info && index->info->loop_type == INF_LOOP) {
		index->end->next = index->start;
		index->start->prev = index->end;
	}
	node->number = index->nb_steps;
	return 0;
}

int move_index__insert_new_node_start(move_index_t *index, sfVector2f acc)
{
	move_node_t *new_node = NULL;

	new_node = move_node__create(acc);
	if (!new_node)
		return -1;
	if (move_index__insert_node_start(index, new_node) == -1)
		return -1;
	return 0;
}

int move_index__insert_new_node_end(move_index_t *index, sfVector2f acc)
{
	move_node_t *new_node = NULL;

	new_node = move_node__create(acc);
	if (!new_node)
		return -1;
	if (move_index__insert_node_end(index, new_node) == -1)
		return -1;
	return 0;
}

int move_index__insert_several_new_node_start(move_index_t *index, sfVector2f acc, size_t nb)
{
	move_node_t *new_node = NULL;
	size_t i = 0;

	for (i = 0; i < nb; i++) {
		new_node = move_node__create(acc);
		if (!new_node)
			return -1;
		if (move_index__insert_node_start(index, new_node) == -1)
			return -1;
		new_node = NULL;
	}
	return 0;
}

int move_index__insert_several_new_node_end(move_index_t *index, sfVector2f acc, size_t nb)
{
	move_node_t *new_node = NULL;
	size_t i = 0;

	for (i = 0; i < nb; i++) {
		new_node = move_node__create(acc);
		if (!new_node)
			return -1;
		if (move_index__insert_node_end(index, new_node) == -1)
			return -1;
		new_node = NULL;
	}
	return 0;
}
