/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** anim_list_delete.c
*/

#include "utilsCSFML.h"

void anim_list_index__remove_head(anim_list_index_t *index)
{
	anim_list_node_t *t_node = NULL;

	if (!index || anim_list_index__is_empty(index))
		return;
	anim_index__destroy(index->head->anim);
	if (index->nb_anims == 1) {
		free(index->head);
		index->head = NULL;
		index->tail = NULL;
		index->nb_anims = 0;
		return;
	}
	t_node = index->head;
	index->head = index->head->prev;
	index->head->next = NULL;
	free(t_node);
	index->nb_anims--;
}

void anim_list_index__remove_tail(anim_list_index_t *index)
{
	anim_list_node_t *t_node = t_node = index->tail;;

	if (!index || anim_list_index__is_empty(index))
		return;
	anim_index__destroy(index->tail->anim);
	if (index->nb_anims == 1) {
		free(index->tail);
		index->tail = NULL;
		index->head = NULL;
		index->nb_anims = 0;
		return;
	}
	index->tail = index->tail->next;
	index->tail->prev = NULL;
	free(t_node);
	index->nb_anims--;
}

void anim_list_index__clean(anim_list_index_t *index)
{
	while (!anim_list_index__is_empty(index))
		anim_list_index__remove_tail(index);
}

void anim_list_index__destroy(anim_list_index_t *index)
{
	anim_list_index__clean(index);
	free(index);
}
