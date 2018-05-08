/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** anim_list_delete.c
*/

#include "utilsCSFML.h"

void move_list_index__remove_head(move_list_index_t *index)
{
	move_list_node_t *t_node = NULL;

	if (!index || move_list_index__is_empty(index))
		return;
	move_index__destroy(index->head->move);
	if (index->nb_moves == 1) {
		free(index->head);
		index->head = NULL;
		index->tail = NULL;
		index->nb_moves = 0;
		return;
	}
	t_node = index->head;
	index->head = index->head->prev;
	index->head->next = NULL;
	free(t_node);
	index->nb_moves--;
}

void move_list_index__remove_tail(move_list_index_t *index)
{
	move_list_node_t *t_node = t_node = index->tail;;

	if (!index || move_list_index__is_empty(index))
		return;
	move_index__destroy(index->tail->move);
	if (index->nb_moves == 1) {
		free(index->tail);
		index->tail = NULL;
		index->head = NULL;
		index->nb_moves = 0;
		return;
	}
	index->tail = index->tail->next;
	index->tail->prev = NULL;
	free(t_node);
	index->nb_moves--;
}

void move_list_index__clean(move_list_index_t *index)
{
	while (!move_list_index__is_empty(index))
		move_list_index__remove_tail(index);
}

void move_list_index__destroy(move_list_index_t *index)
{
	move_list_index__clean(index);
	free(index);
}
