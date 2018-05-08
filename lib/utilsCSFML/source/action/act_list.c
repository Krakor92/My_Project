/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that are relative to the basics of double linked lists
*/

#include "utilsCSFML.h"

act_list_index_t *act_list_index__malloc(void)
{
	act_list_index_t *index = NULL;

	index = malloc(sizeof(*index));
	if (!index)
		return my_ptr_error(INVALID_MALLOC);
	index->nb_acts = 0;
	index->head = NULL;
	index->tail = NULL;
	return index;
}

act_list_index_t *act_list_index__create(void)
{
	act_list_index_t *index = NULL;

	index = act_list_index__malloc();
	if (!index)
		return NULL;
	return index;
}

act_list_node_t *act_list_node__malloc(void)
{
	act_list_node_t *node = NULL;

	node = malloc(sizeof(*node));
	if (!node)
		return my_ptr_error(INVALID_MALLOC);
	node->act = NULL;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

act_list_node_t *act_list_node__create(act_t *act)
{
	act_list_node_t *node = NULL;

	node = act_list_node__malloc();
	if (!node)
		return NULL;
	node->act = act;
	return node;
}

bool_t act_list_index__is_empty(act_list_index_t *index)
{
	if (index->nb_acts == 0 && !index->head && !index->tail)
		return TRUE;
	return FALSE;
}
