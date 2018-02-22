/*
** EPITECH PROJECT, 2017
** [N/A] {Vincent FAIVRE}
** File description:
** Functions that are relative to the basics of double linked lists
*/

#include "str_dlist.h"

DListIndex_t *get_new_dlist(void)
{
	DListIndex_t *dlist;

	dlist = malloc(sizeof(DListIndex_t));
	if (dlist == NULL)
		return (NULL);
	dlist->length = 0;
	dlist->head = NULL;
	dlist->tail = NULL;
	return (dlist);
}

DListNode_t *get_new_node(char *str)
{
	DListNode_t *newnode;

	newnode = malloc(sizeof(DListNode_t));
	if (newnode == NULL)
		return (my_ptr_error(INVALID_MALLOC));
	newnode->val = str;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

int dlist_is_null(DListIndex_t *dlist)
{
	if (dlist == NULL)
		return (true);
	return (false);
}

int dlist_is_empty(DListIndex_t *dlist)
{
	if (dlist->length == 0 && dlist->head == NULL && dlist->tail == NULL)
		return (true);
	return (false);
}
