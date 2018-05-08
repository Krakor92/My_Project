/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that are relative to the basics of double linked lists
*/

#include "utilsCSFML.h"

move_index_t *move_index__malloc(void)
{
	move_index_t *index = NULL;

	index = malloc(sizeof(*index));
	if (!index)
		return my_ptr_error(INVALID_MALLOC);
	index->name = NULL;
	index->nb_steps = 0;
	index->info = NULL;
	index->chrono = NULL;
	index->start = NULL;
	index->end = NULL;
	index->current = NULL;
	index->started = FALSE;
	index->finished = FALSE;
	index->active = FALSE;
	return index;
}

move_index_t *move_index__create(char *name,
				move_type_t type,
				move_loop_type_t loop_type,
				chrono_t *chrono)
{
	move_index_t *index = NULL;

	index = move_index__malloc();
	if (!index)
		return NULL;
	index->name = name;
	index->info = move_info__create(type, loop_type);
	index->chrono = chrono;
	return index;
}

move_node_t *move_node__malloc(void)
{
	move_node_t *node = NULL;

	node = malloc(sizeof(*node));
	if (!node)
		return my_ptr_error(INVALID_MALLOC);
	node->number = 0;
	node->acc = (sfVector2f){0, 0};
	node->next = NULL;
	node->prev = NULL;
	return node;
}

move_node_t *move_node__create(sfVector2f acc)
{
	move_node_t *node = NULL;

	node = move_node__malloc();
	if (!node)
		return NULL;
	node->acc = acc;
	return node;
}

bool_t move_index__is_empty(move_index_t *index)
{
	if (index->nb_steps == 0 && !index->start && !index->end)
		return TRUE;
	return FALSE;
}

//A TESTER!
void move_index__set_move_node_current(move_index_t *move, size_t node_nb)
{
	size_t i = 1;

	if (!move || !node_nb || node_nb > move->nb_steps)
		return;
	move->current = move->start;
	for (i = 1; i < node_nb; i++)
		move->current = move->current->next;
	move->started = TRUE;//très important;
}
