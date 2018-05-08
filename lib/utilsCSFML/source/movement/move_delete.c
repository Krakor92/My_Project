/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that delete or clean dlist
*/

#include "utilsCSFML.h"

void move_node__destroy(move_node_t *node)
{
	if (!node)
		return;
	if (node->next && node->prev) {
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}
	if (node->next && !node->prev)
		node->next->prev = NULL;
	if (!node->next && node->prev)
		node->prev->next = NULL;
	node->next = NULL;
	node->prev = NULL;
	free(node);
	node = NULL;
}

void move_index__remove_start(move_index_t *index)
{
	move_node_t *t_node = NULL;

	if (!index || move_index__is_empty(index))
		return;
	if (index->nb_steps == 1) {
		move_node__destroy(index->start);
		index->start = NULL;
		index->end = NULL;
		index->nb_steps = 0;
		return;
	}
	t_node = index->start;
	index->start = index->start->next;
	index->start->prev = NULL;
	move_node__destroy(t_node);
	index->nb_steps--;
}

void move_index__remove_end(move_index_t *index)
{
	move_node_t *t_node = NULL;

	if (!index || move_index__is_empty(index))
		return;
	if (index->nb_steps == 1) {
		move_node__destroy(index->end);
		index->end = NULL;
		index->start = NULL;
		index->nb_steps = 0;
		return;
	}
	t_node = index->end;
	index->end = index->end->prev;
	index->end->next = NULL;
	move_node__destroy(t_node);
	index->nb_steps--;
}

void move_index__clean(move_index_t *index)
{
	while (!move_index__is_empty(index))
		move_index__remove_end(index);
}

void move_index__destroy(move_index_t *index)
{
	move_index__clean(index);
	move_info__destroy(index->info);
	chrono__destroy(index->chrono);
	free(index);
	index = NULL;
}
