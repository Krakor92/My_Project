/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions whose are related to the head and tail of dlists
*/

#include "str_dlist.h"

int get_dlist_length(DListIndex_t *dlist)
{
	if (dlist_is_null(dlist))
		return (-1);
	return (dlist->length);
}

char *get_dlist_head_value(DListIndex_t *dlist)
{
	if (dlist_is_null(dlist) || dlist_is_empty(dlist))
		return (NULL);
	return (dlist->head->val);
}

char *get_dlist_tail_value(DListIndex_t *dlist)
{
	if (dlist_is_null(dlist) || dlist_is_empty(dlist))
		return (0);
	return (dlist->tail->val);
}

int insert_head_dlist(DListIndex_t *dlist, char *str)
{
	DListNode_t *element;
	element = get_new_node(str);

	if (element == NULL)
		return (-1);
	if (dlist_is_null(dlist)) {
		dlist = get_new_dlist();
		if (dlist == NULL)
			return (-1);
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
	return (0);
}

int insert_tail_dlist(DListIndex_t *dlist, char *str)
{
	DListNode_t *element;
	element = get_new_node(str);

	if (element == NULL)
		return (-1);
	if (dlist_is_null(dlist)) {
		dlist = get_new_dlist();
		if (dlist == NULL)
			return (-1);
	}
	if (dlist_is_empty(dlist)) {
		dlist->length += 1;
		dlist->head = element;
		dlist->tail = element;
	} else {
		dlist->length += 1;
		dlist->tail->prev = element;
		element->next = dlist->tail;
		dlist->tail = element;
	}
	return (0);
}
