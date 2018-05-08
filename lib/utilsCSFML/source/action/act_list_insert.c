/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions whose are related to the head and tail of dlists
*/

#include "utilsCSFML.h"

int act_list_index__insert_node_tail(act_list_index_t *index,
				     act_list_node_t *node)
{
	if (!index || !node)
		return my_int_error("Insertion aborted!\n");
	if (act_list_index__is_empty(index)) {
		index->head = node;
		index->tail = node;
		index->nb_acts = 1;
	}
	else {
		index->tail->prev = node;
		node->next = index->tail;
		index->tail = node;
		index->nb_acts++;
	}
	return 0;
}

int act_list_index__insert_node_head(act_list_index_t *index,
				     act_list_node_t *node)
{
	if (!index || !node)
		return my_int_error("Insertion aborted!\n");
	if (act_list_index__is_empty(index)) {
		index->head = node;
		index->tail = node;
		index->nb_acts = 1;
	}
	else {
		index->head->next = node;
		node->prev = index->head;
		index->head = node;
		index->nb_acts++;
	}
	return 0;
}

int act_list_index__insert_new_node_tail(act_list_index_t *index,
					 act_t *act)
{
	act_list_node_t *new_node = NULL;

	new_node = act_list_node__create(act);
	if (!new_node)
		return -1;
	if (act_list_index__insert_node_tail(index, new_node) == -1)
		return -1;
	return 0;
}

int act_list_index__insert_new_node_head(act_list_index_t *index,
					 act_t *act)
{
	act_list_node_t *new_node = NULL;

	new_node = act_list_node__create(act);
	if (!new_node)
		return -1;
	if (act_list_index__insert_node_head(index, new_node) == -1)
		return -1;
	return 0;
}
