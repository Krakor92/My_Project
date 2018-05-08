/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** anim_list_delete.c
*/

#include "utilsCSFML.h"

void act_list_index__remove_head(act_list_index_t *index)
{
	act_list_node_t *t_node = NULL;

	if (!index || act_list_index__is_empty(index))
		return;
	act__destroy(index->head->act);
	if (index->nb_acts == 1) {
		free(index->head);
		index->head = NULL;
		index->tail = NULL;
		index->nb_acts = 0;
		return;
	}
	t_node = index->head;
	index->head = index->head->prev;
	index->head->next = NULL;
	free(t_node);
	index->nb_acts--;
}

void act_list_index__remove_tail(act_list_index_t *index)
{
	act_list_node_t *t_node = NULL;

	if (!index || act_list_index__is_empty(index))
		return;
	t_node = index->tail;
	act__destroy(index->tail->act);
	if (index->nb_acts == 1) {
		free(index->tail);
		index->tail = NULL;
		index->head = NULL;
		index->nb_acts = 0;
		return;
	}
	index->tail = index->tail->next;
	index->tail->prev = NULL;
	free(t_node);
	index->nb_acts--;
}

void act_list_index__clean(act_list_index_t *index)
{
	if (!index)
		return;
	while (!act_list_index__is_empty(index))
		act_list_index__remove_tail(index);
}

void act_list_index__destroy(act_list_index_t *index)
{
	if (!index)
		return;
	act_list_index__clean(index);
	free(index);
	index = NULL;
}

static void act_list_index__remove_tail_soft(act_list_index_t *index)
{
	act_list_node_t *t_node = NULL;

	if (!index || act_list_index__is_empty(index))
		return;
	t_node = index->tail;
	if (index->nb_acts == 1) {
		free(index->tail);
		index->tail = NULL;
		index->head = NULL;
		index->nb_acts = 0;
		return;
	}
	index->tail = index->tail->next;
	index->tail->prev = NULL;
	free(t_node);
	index->nb_acts--;
}

void act_list_index__destroy_soft(act_list_index_t *index)
{
	if (!index)
		return;
	while (!act_list_index__is_empty(index))
		act_list_index__remove_tail_soft(index);
	free(index);
	index = NULL;
}
