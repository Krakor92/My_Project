/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that delete or clean dlist
*/

#include "utilsCSFML.h"

void anim_index__remove_start(anim_index_t *index)
{
	anim_node_t *t_node = NULL;

	if (!index || anim_index__is_empty(index))
		return;
	if (index->nb_frames == 1) {
		free(index->start);
		index->start = NULL;
		index->end = NULL;
		index->nb_frames = 0;
		return;
	}
	t_node = index->start;
	index->start = index->start->next;
	index->start->prev = NULL;
	free(t_node);
	index->nb_frames--;
}

void anim_index__remove_end(anim_index_t *index)
{
	anim_node_t *t_node = NULL;

	if (!index || anim_index__is_empty(index))
		return;
	if (index->nb_frames == 1) {
		free(index->end);
		index->end = NULL;
		index->start = NULL;
		index->nb_frames = 0;
		return;
	}
	t_node = index->end;
	index->end = index->end->prev;
	index->end->next = NULL;
	free(t_node);
	index->nb_frames--;
}

void anim_index__clean(anim_index_t *index)
{
	while (!anim_index__is_empty(index))
		anim_index__remove_end(index);
}

void anim_index__destroy(anim_index_t *index)
{
	anim_index__clean(index);
	chrono__destroy(index->chrono);
	free(index);
}
