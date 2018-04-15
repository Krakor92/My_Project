/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that are relative to the basics of double linked lists
*/

#include "utilsCSFML.h"

anim_index_t *anim_index__malloc(void)
{
	anim_index_t *index = NULL;

	index = malloc(sizeof(*index));
	if (!index)
		return my_ptr_error(INVALID_MALLOC);
	index->name = NULL;
	index->texture = NULL;
	index->nb_frames = 0;
	index->chrono = NULL;
	index->start = NULL;
	index->end = NULL;
	index->current = NULL;
	index->finished = FALSE;
	index->loop = FALSE;
	return index;
}

anim_index_t *anim_index__create(char *name,
			    sfTexture *ttr,
			     chrono_t *chrono,
			       bool_t loop)
{
	anim_index_t *index = NULL;

	index = anim_index__malloc();
	if (!index)
		return NULL;
	index->name = name;
	index->texture = ttr;
	index->chrono = chrono;
	index->loop = loop;
	return index;
}

anim_node_t *anim_node__malloc(void)
{
	anim_node_t *node = NULL;

	node = malloc(sizeof(*node));
	if (!node)
		return my_ptr_error(INVALID_MALLOC);
	node->next = NULL;
	node->prev = NULL;
	return node;
}

anim_node_t *anim_node__create(sfIntRect rect, double on)
{
	anim_node_t *node = NULL;

	node = anim_node__malloc();
	if (!node)
		return NULL;
	node->rect = rect;
	node->on = on;
	return node;
}

bool_t anim_index__is_empty(anim_index_t *index)
{
	if (index->nb_frames == 0 && !index->start && !index->end)
		return TRUE;
	return FALSE;
}
