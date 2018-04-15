/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that are relative to the basics of double linked lists
*/

#include "utilsCSFML.h"

anim_list_index_t *anim_list_index__malloc(void)
{
	anim_list_index_t *index = NULL;

	index = malloc(sizeof(*index));
	if (!index)
		return my_ptr_error(INVALID_MALLOC);
	index->nb_anims = 0;
	index->head = NULL;
	index->tail = NULL;
	return index;
}

anim_list_index_t *anim_list_index__create(void)
{
	anim_list_index_t *index = NULL;

	index = anim_list_index__malloc();
	if (!index)
		return NULL;
	return index;
}

anim_list_node_t *anim_list_node__malloc(void)
{
	anim_list_node_t *node = NULL;

	node = malloc(sizeof(*node));
	if (!node)
		return my_ptr_error(INVALID_MALLOC);
	node->anim = NULL;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

anim_list_node_t *anim_list_node__create(anim_index_t *anim)
{
	anim_list_node_t *node = NULL;

	node = anim_list_node__malloc();
	if (!node)
		return NULL;
	node->anim = anim;
	return node;
}

bool_t anim_list_index__is_empty(anim_list_index_t *index)
{
	if (index->nb_anims == 0 && !index->head && !index->tail)
		return TRUE;
	return FALSE;
}
