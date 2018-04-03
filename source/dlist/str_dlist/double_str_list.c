/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that are relative to the basics of double linked lists
*/

#include "str_dlist.h"

dlist_index_t *get_new_dlist(void)
{
	dlist_index_t *dlist = NULL;

	dlist = malloc(sizeof *dlist);
	if (!dlist)
		return my_ptr_error(INVALID_MALLOC);
	dlist->length = 0;
	dlist->head = NULL;
	dlist->tail = NULL;
	return dlist;
}

dlist_node_t *get_new_node(char *str)
{
	dlist_node_t *newnode = NULL;

	newnode = malloc(sizeof *newnode);
	if (!newnode)
		return my_ptr_error(INVALID_MALLOC);
	newnode->val = str;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

int dlist_is_null(dlist_index_t *dlist)
{
	if (!dlist)
		return true;
	return false;
}

int dlist_is_empty(dlist_index_t *dlist)
{
	if (dlist->length == 0 && !dlist->head && !dlist->tail)
		return true;
	return false;
}
