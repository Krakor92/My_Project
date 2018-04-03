/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions whose are related to the head and tail of dlists
*/

#include "str_dlist.h"

int get_dlist_length(dlist_index_t *dlist)
{
	if (dlist_is_null(dlist))
		return -1;
	return dlist->length;
}

char *get_dlist_head_value(dlist_index_t *dlist)
{
	if (dlist_is_null(dlist) || dlist_is_empty(dlist))
		return NULL;
	return dlist->head->val;
}

char *get_dlist_tail_value(dlist_index_t *dlist)
{
	if (dlist_is_null(dlist) || dlist_is_empty(dlist))
		return NULL;
	return dlist->tail->val;
}

int insert_head_dlist(dlist_index_t *dlist, char *str)
{
	dlist_node_t *element = NULL;
	element = get_new_node(str);

	if (!element)
		return -1;
	if (dlist_is_null(dlist)) {
		dlist = get_new_dlist();
		if (!dlist)
			return -1;
	}
	if (dlist_is_empty(dlist)) {
		dlist->length++;
		dlist->head = element;
		dlist->tail = element;
	} else {
		dlist->length++;
		dlist->head->next = element;
		element->prev = dlist->head;
		dlist->head = element;
	}
	return 0;
}

int insert_tail_dlist(dlist_index_t *dlist, char *str)
{
	dlist_node_t *element = NULL;
	element = get_new_node(str);

	if (!element)
		return -1;
	if (dlist_is_null(dlist)) {
		dlist = get_new_dlist();
		if (!dlist)
			return -1;
	}
	if (dlist_is_empty(dlist)) {
		dlist->length++;
		dlist->head = element;
		dlist->tail = element;
	} else {
		dlist->length++;
		dlist->tail->prev = element;
		element->next = dlist->tail;
		dlist->tail = element;
	}
	return 0;
}
